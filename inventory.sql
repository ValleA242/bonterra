/*
This file contains a script of MySQL commands for creating, populating, and querying a 'Categories' table and related 'Products' table. 

Assumptions:
- MySQL version 8 is installed and running
- database 'Inventory' already exists.
*/

-- Set the default database to 'Inventory'
USE Inventory;

/*
Create a Catagory table with the following columns:
- CategoryID (Primary Key)
- CategoryName (Unique)
- Description (Optional)

Rules:
Create the table only if one does not already exist.
*/
CREATE TABLE IF NOT EXISTS Categories (
    CategoryID INT AUTO_INCREMENT PRIMARY KEY,
    CategoryName VARCHAR(50) UNIQUE,
    Description TEXT
);

/*
Create a Products table with the following columns:
- ProductID (Primary Key)
- ProductName 
- Price
- CategoryID (Foreign Key)

Rules:
Create the table only if one does not already exist.
*/
CREATE TABLE IF NOT EXISTS Products (
    ProductID INT AUTO_INCREMENT PRIMARY KEY,
    ProductName VARCHAR(50),
    Price DECIMAL(10, 2),
    CategoryID INT,
    FOREIGN KEY (CategoryID) REFERENCES Categories(CategoryID)
);

/*
Populate the Categories table.
*/
INSERT INTO Categories (CategoryName, Description) VALUES
('Electronics', 'Electronic devices and accessories'),
('Clothing', 'Clothing and apparel'),
('Books', 'Books and literature');

/*
Populate the Products table.
*/
INSERT INTO Products (ProductName, Price, CategoryID) VALUES
('Laptop', 999.99, 1),
('Smartphone', 599.99, 1),
('T-shirt', 19.99, 2),
('Jeans', 39.99, 2),
('Novel', 14.99, 3),
('Textbook', 99.99, 3);



/*
Query the Categories table to display all categories.
*/

SELECT * FROM Categories;

/*
Query the Products table to display all products in descending order of price.
*/

SELECT * FROM Products ORDER BY Price DESC;

/*
Query the Products table to display all products in a specific category (e.g., Electronics).
*/

SELECT * FROM Products WHERE CategoryID = 1;



