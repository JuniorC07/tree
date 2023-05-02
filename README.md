## Readme - University assignment

### Introduction
This code implements a binary tree in C++. The tree has the capability to insert, search, show and balance nodes. 

### Dependencies
The code uses the C++ standard library and doesn't have any external dependencies.

### Installation
To install the code, you need to have a C++ compiler installed on your computer. After that, you can download or copy and paste the code into a text editor, save the file with the .cpp extension and compile it using your compiler. 

### How to use
After compiling the code, you can execute the binary file generated by the compiler to start using the binary tree. The main function creates a binary tree and inserts some nodes into it. You can modify the nodes or insert new ones by calling the `insere` method of the `nodo` class. 

To search for a node in the tree, you can call the `buscar` method passing the root node of the tree and the value you want to search for. The method will return a pointer to the node if it exists or null otherwise.

To show the nodes in the tree, you can call the `mostra_em_ordem`, `mostra_pre_ordem` or `mostra_pos_ordem` method, depending on the order you want to show the nodes.

To balance the tree, you can call the `balancear` method, passing the root node of the tree. The method will balance the tree using the AVL algorithm.

To delete a node from the tree, you can call the `exclui` method, passing the node you want to delete. The method will delete the node and adjust the links between the other nodes in the tree.

## How to compile

To compile the program, execute the following command in a Linux terminal:

```
g++ main.cpp -o main
```

## How to run

After compiling the program, run it with the following command:

```
./main
```
## Author

- [Junior Camargo](https://github.com/JuniorC07)

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for more information.