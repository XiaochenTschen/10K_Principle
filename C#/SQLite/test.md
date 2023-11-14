```c#
using System;
using Microsoft.Data.Sqlite; // 或者使用 System.Data.SQLite;

class Program
{
    static void Main()
    {
        string connectionString = "Data Source=path_to_your_db_file.db;";
        using (var connection = new SqliteConnection(connectionString))
        {
            connection.Open();

            string sql = "SELECT * FROM your_table_name;";
            using (var command = new SqliteCommand(sql, connection))
            {
                using (var reader = command.ExecuteReader())
                {
                    while (reader.Read())
                    {
                        Console.WriteLine(reader["column_name"].ToString());
                    }
                }
            }
        }
    }
}

```