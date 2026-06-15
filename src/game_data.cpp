#include "game_data.hpp"

Database_interface::Database_interface()
{
    init_db();
}

void Database_interface::init_db()
{
    sqlite3_open("game.db", &db_handle);

    char* error_msg = nullptr;
    int rc;

    // players table
    rc = sqlite3_exec(db_handle, R"sql(
        CREATE TABLE IF NOT EXISTS players(
        player_id INTEGER PRIMARY KEY AUTOINCREMENT,
        player_name TEXT NOT NULL
        );
    )sql", nullptr, nullptr, &error_msg);

    if (rc != SQLITE_OK) {
        std::cerr << "Error creating players table: " << error_msg << std::endl;
        sqlite3_free(error_msg);
    }


    // monsters table
    rc = sqlite3_exec(db_handle, R"sql(
        CREATE TABLE IF NOT EXISTS monsters(
        monster_id INTEGER PRIMARY KEY AUTOINCREMENT,
        monster_name TEXT NOT NULL,
        monster_hp INTEGER NOT NULL,
        monster_dmg INTEGER NOT NULL
        );
    )sql", nullptr, nullptr, &error_msg);

    if (rc != SQLITE_OK) {
        std::cerr << "Error creating monsters table: " << error_msg << std::endl;
        sqlite3_free(error_msg);
    }


    // player_monsters table
    rc = sqlite3_exec(db_handle, R"sql(
        CREATE TABLE IF NOT EXISTS player_monsters(
        player_monster_id INTEGER PRIMARY KEY AUTOINCREMENT,
        player_id INTEGER NOT NULL,
        monster_id INTEGER NOT NULL,
        FOREIGN KEY (player_id) REFERENCES players(player_id) ON DELETE CASCADE,
        FOREIGN KEY (monster_id) REFERENCES monsters(monster_id) ON DELETE CASCADE
        );
    )sql", nullptr, nullptr, &error_msg);

    if (rc != SQLITE_OK) {
        std::cerr << "Error creating player_monsters table: " << error_msg << std::endl;
        sqlite3_free(error_msg);
    }


    // insert monsters
    std::string insert_sql = R"sql(
        INSERT OR IGNORE INTO monsters (monster_name, monster_hp, monster_dmg) VALUES
        ('none', 0, 0),
        ('Hest', 4, 1),
        ('Weak Goblin', 4, 2),
        ('Strong Goblin', 8, 3),
        ('Stronger Goblin', 10, 4),
        ('Den stærkeste Goblin', 15, 5),
        ('Abe Kongen', 30, 5),
        ('Enhjørning', 50, 8),
        ('Drage', 100, 10);
    )sql";

    rc = sqlite3_exec(db_handle, insert_sql.c_str(), nullptr, nullptr, &error_msg);

    if (rc != SQLITE_OK) {
        std::cerr << "Error inserting monsters: " << error_msg << std::endl;
        sqlite3_free(error_msg);
    }
}


void Database_interface::save_game_data(Player data)
{
    char* error_message = nullptr;

    std::cout << "step 1" << std::endl;
    std::string sql_command =
        "INSERT INTO players (player_name) VALUES ('" + data.get_name() + "');";

    std::cout << sql_command << std::endl;

    int result = sqlite3_exec(db_handle, sql_command.c_str(), nullptr, nullptr, &error_message);

    std::cout << "step 2 &   " << result << std::endl;

    if (result != SQLITE_OK)
    {
        if(error_message != nullptr)
        {std::cout << "SQL error: " << error_message << std::endl;
        sqlite3_free(error_message);}
    }
    
    std::cout << "step 2b" << std::endl;

    // sql_command = "SELECT player_id FROM players WHERE player_name = '" + data.get_name() + "';";
    // sqlite3_exec(db_handle, sql_command.c_str(), nullptr, nullptr, nullptr);

    int player_id = sqlite3_last_insert_rowid(db_handle);

    std::cout << "step 3" << std::endl;

    for (auto monster : data.get_all_monsters())
    {
        sql_command =
            "INSERT INTO player_monsters (player_id, monster_id) VALUES ("+ std::to_string(player_id) +", (SELECT monster_id FROM monsters WHERE monster_name = '"+ monster.name +"')) ";
        std::cout << sql_command << std::endl;

        sqlite3_exec(db_handle, sql_command.c_str(), nullptr, nullptr, nullptr);
    }
    std::cout << "step 4" << std::endl;
}




Player Database_interface::load_game_data(int game_id)
{
    return Player();
}

std::vector<std::string> Database_interface::show_saved_games()
{
    return std::vector<std::string>();
}
