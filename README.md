# Carbon Credit Shopping System

## Overview

The Carbon Credit Shopping System is a command-line application developed in C that allows users to manage a product catalog and a shopping cart. This system is designed to align with Objective 9: Building resilient infrastructure, promoting inclusive and sustainable industrialization, and fostering innovation, with a particular focus on carbon credits.

## Features

- **Product Management**: Administrators can add, remove, and modify products in the catalog. Each product includes details such as name, stock quantity, value, and carbon emission quantity.
- **Shopping Cart Management**: Customers can add items to their cart, remove items from their cart, and view the contents of their cart.
- **Purchase Completion**: Customers can finalize their purchases, with the system calculating the total amount due.
- **Search and Filter**: Customers can search for products by name, code, or price, and filter products based on these criteria.

## Data Structures

- **Carrinho**: Represents an item in the shopping cart with product code, quantity, and value.
- **Produtos**: Represents a product with attributes such as name, code, stock quantity, value, and carbon emission quantity.

## User Roles

1. **Customer**:
   - View available products.
   - Search for products by name, code, or price.
   - Add items to the shopping cart.
   - Remove items from the shopping cart.
   - View the contents of the shopping cart.
   - Complete the purchase of items in the shopping cart.

2. **Administrator**:
   - Add new products to the catalog.
   - Remove products from the catalog.
   - Edit product details such as name, stock quantity, value, and carbon emission quantity.
   - View the list of all products in the catalog.

## Usage

1. **Compile the Code**: Use a C compiler to compile the source code.
2. **Run the Program**: Execute the compiled program in the terminal.
3. **Choose User Role**: Select whether you are a customer or an administrator.
4. **Follow the Menu Options**: Interact with the system based on your role to manage products or shopping cart operations.

## Future Enhancements

- **Data Persistence**: Implement data storage to save product details and completed transactions.
- **User Authentication**: Add authentication to manage different user roles securely.
- **Advanced Shopping Cart**: Enhance cart functionality to allow editing item quantities and other improvements.

## License

This project is open source and available for free. There are no specific licensing requirements.
