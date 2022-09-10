# linux-c-revshell
Linux Reverse Shell Written in C


Build Dependencies:
  - CMake
  - Compiler ( GCC )
  
# Configuration
This project uses cmake for configuring project and building it. For configuring the project use the following Command:
```
cmake -Bbuild -DIP="x.x.x.x" -DPORT=XXXX
```

Before executing command substitute your ip with x.x.x.x and your port with XXXX.

# Building
For building project using CMake execute the following command:
```
cmake --build build
```
Then the executable Reverse shell is in the `build` folder.

# Run
Now send your reverse-shell to your target, then put your server ( PC ) to listen for shell.<br>
For Putting your server ( PC ) to listen using netcat you should use following command:
```
nc -lvp PORT
```
And substitute the Port you have chosen while build with PORT.

Now you got the Shell, Have Fun :).

# Contributors

The only developer of this project is now iHapiW
