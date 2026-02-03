#include <iostream>
#include <cstring>
#include <string>
#include <mariadb/conncpp.hpp>
#include "ConnectingToDatabase.h"
using namespace std;

// Delete a task record (indicated by id)
//This would be getting rid of something in the database
void deleteTask(std::unique_ptr<sql::Connection>& conn, int id) {
    try {
        // Create a new PreparedStatement
        std::unique_ptr<sql::PreparedStatement> stmnt(conn->prepareStatement("delete from tasks where id = ?"));
        // Bind values to SQL statement
        stmnt->setInt(1, id);
        // Execute query
        stmnt->executeQuery();
    }
    catch (sql::SQLException& e) {
        std::cerr << "Error deleting task: " << e.what() << std::endl;
    }
}

// Update the completed value of a task record (indicated by id)
void updateTaskStatus(std::unique_ptr<sql::Connection>& conn, int id, bool completed) {
    try {
        // Create a new PreparedStatement
        std::unique_ptr<sql::PreparedStatement> stmnt(conn->prepareStatement("update tasks set completed = ? where id = ?"));
        // Bind values to SQL statement
        stmnt->setBoolean(1, completed);
        stmnt->setInt(2, id);
        // Execute query
        stmnt->executeQuery();
    }
    catch (sql::SQLException& e) {
        std::cerr << "Error updating task status: " << e.what() << std::endl;
    }
}

// Create a new task record
void addTask(std::unique_ptr<sql::Connection>& conn, std::string description) {
    try {
        // Create a new PreparedStatement
        std::unique_ptr<sql::PreparedStatement> stmnt(conn->prepareStatement("insert into tasks (description) values (?)"));
        // Bind values to SQL statement
        stmnt->setString(1, description);
        // Execute query
        stmnt->executeQuery();
    }
    catch (sql::SQLException& e) {
        std::cerr << "Error inserting new task: " << e.what() << std::endl;
    }
}

//Picks out the data wanted and prints it out
void showTasks(std::unique_ptr<sql::Connection>& conn) {
    try {
        // Create a new Statement
        std::unique_ptr<sql::Statement> stmnt(conn->createStatement());
        // Execute query
        //Change the line of code below it from author later to make it so it can be changed to any table
        //sql::ResultSet* res = stmnt->executeQuery("select * from author");

        /*
        * sql::ResultSet* res = stmnt->executeQuery("CALL getBooksByAuthor(\'Matt Mit\');");
        */
        string lookingFor;
        cout << "Enter the name of the author you are looking for >> ";
        std::getline(std::cin, lookingFor);
        sql::ResultSet* res = stmnt->executeQuery("select * from author where Aname like \'" + lookingFor + "\'");
        

        

        //sql::ResultSet* res = stmnt->executeQuery("select * from author where Aname like \'Mario Livio\'");
 
        //prints out all the results
        // Loop through and print results
        int count = 1;
        while (res->next()) {
            //std::cout << "Author name = " << res->getString(1);
            std::cout << "ISBN = " <<  res->getString(1) << "\t count:" << count << "\n";
            //std::cout << ", description = " << res->getString(2);
            //std::cout << ", completed = " << res->getBoolean(3) << "\n";
            count++;
        }
    }
    catch (sql::SQLException& e) {
        std::cerr << "Error selecting tasks: " << e.what() << std::endl;
    }
}

//GetAllAuthors, GetAllFormats,GetAllGenres
void GetAllOfSomething(std::unique_ptr<sql::Connection>& conn)
{
    string UserInput;

    cout << "Enter your choice (1,2,3) >> ";
    cin >> UserInput;
    //Fix this to line up with gui but basically if 1 --> GetAllAtuhors is called
    //If 2 --> GetAllFormats is called
    // if 3 --> GetAllGenres is called
    //code to execute the stored proceudre

    std::unique_ptr<sql::Statement> stmnt(conn->createStatement());
    if (UserInput == "1")
    {
        try
        {
            sql::ResultSet* res = stmnt->executeQuery("CALL GetAllAuthors();");
            //while loop goes through and prints out all authors
            //count is meant to help keep track of how many were printed
            int count = 1;
            while (res->next())
            {
                std::cout << "Author Name: " << res->getString(1) << "\t Count:" << count << "\n\n";
                count++;
            }
        }
        catch (sql::SQLException& e)
        {
            std::cout << "Error selecting tasks;" << e.what() << std::endl;
        }
    }
    if (UserInput == "2")
    {
        try
        {
            sql::ResultSet* res = stmnt->executeQuery("CALL GetAllFormats();");
            //while loop goes through and prints out all authors
            //count is meant to help keep track of how many were printed
            int count = 1;
            while (res->next())
            {
                std::cout << "Format type: " << res->getString(1) << "\t Count:" << count << "\n\n";
                count++;
            }
        }
        catch (sql::SQLException& e)
        {
            std::cout << "Error selecting tasks;" << e.what() << std::endl;
        }
    }
    if (UserInput == "3")
    {
       try
       {
            sql::ResultSet* res = stmnt->executeQuery("CALL GetAllGenres();");
            //while loop goes through and prints out all authors
            //count is meant to help keep track of how many were printed
            int count = 1;
            while (res->next())
            {
                std::cout << "Genre type: " << res->getString(1) << "\t Count:" << count << "\n\n";
                count++;
            }
       }
       catch (sql::SQLException& e)
       {
           std::cout << "Error selecting tasks;" << e.what() << std::endl;
       }
    }

}





// Main Process
int main()
{
        try 
        {
            // Instantiate Driver
            sql::Driver* driver = sql::mariadb::get_driver_instance();

            // Configure Connection
            // Next two commented lines are the lines going to be used to access the database when on school wifi using putty. 
            //sql::SQLString url("jdbc:mariadb://washington.uww.edu:3306/cs366-2247_strohkm03");
            sql::SQLString url("jdbc:mariadb://localhost:3306/cs366strohkm03");
            sql::Properties properties({ {"user", "root"}, {"password", "Suffering101"} });

            // Establish Connection
            std::unique_ptr<sql::Connection> conn(driver->connect(url, properties));
            
            //Calls the function showTasks which prints out what the sql statement searched for
            
            showTasks(conn);
            //GetAllOfSomething(conn);
           

            // Close Connection
            conn->close();
        }
        catch (sql::SQLException& e) 
        {
            std::cerr << "Error Connecting to MariaDB Platform: " << e.what() << std::endl;
            // Exit (Failed)
            return 1;
        }
    // Exit (Success)
    return 0;
}