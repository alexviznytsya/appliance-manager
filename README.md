# appliance-manager
Implementation of C++11 Smart Pointers

This project is emulation of an e-commerce site for selling household appliances, such as dishwashers, laundry machines, and clothes dryers. This emulator program manages the appliances for sale on customer's website. Each appliance contains the following fields:
1. **ID** — A unique (integer) identifier for each appliance.
2. **Type** — A type of an appliance is an enumeration with possible values of LAUNDRY MACHINE,
DISH WASHER, and DRYER.
3. **Manufacturer** — A string denoting the company making the appliance (e.g., “Whirpool”).
4. **Price** — A price of the product in US dollars and cents.
5. **Pictures** — An array of file paths containing a list of pictures for each appliance in an appropriate format (e.g., PNG, JPEG, etc.).

Lets say that the last field **Pictures** array has many hight quality pictures of a specific appliance, and to hold all appliances pictures in the main memory is impossible in the customer's server RAM. To avoid cluttering the primary memory of with pictures, application stores appliance instances in files most of the time. Each such file contains information a single appliance instance including its ID, Type, Manufacturer, etc. Moreove application use custom implementation of a smart pointer class called AppliancePtr that dynamically loads instances of class Appliance when they are needed and stores them back on file when done with an appliance.

This program contains just 10 appliances denoted by unique IDs 0 through 9. Each of the ten instances is stored in a separate file. At any point in time, only three of the appliance instances can be stored in memory; the remaining instances exist only in the ten files associated with the project.
When the program is started, the program creates a linked list of 10 appliance pointers; however, none of the appliance instances are loaded in memory. Next, appliances are loaded from memory and stored back to files (possibly after being modified) as needed while executing the commands described next. However, program never holds more than 3 appliance instances in memory at all times.

The command line interface will prompt the user for a command, and then execute the command. Here is a list of commands:

1. **l** — List all appliances. Each appliance is loaded from disk and its information (ID, Type, etc.) is displayed in the user’s screen, including the list of file paths, but with no images of the appliance. Appliance instances are stored back on disk and deleted as needed to keep a maximum of three total appliances in memory at all times.
2. **0 . . . 9** — Edit an appliance. This command sets the numbered appliance to be the current appliance. If the appliance is not already in memory, it is loaded from disk and assigned to the corresponding appliance pointer. In this case, an appliance instance currently in memory may have to be stored back into its corresponding file and deleted from memory not to exceed the limit of 3 appliances.
3. **c** — Create an appliance. The user is prompted for the various fields in the appliance instance. The appliance is then stored to a file and associated smart pointer instance. The appliance’s ID must be between 0 and 9. If an appliance with the same ID existed before this appliance is created, the older appliance is deleted from both memory and the associated file.
4. **p** — This command changes the price of the current appliance. The user is prompted for a new number, which becomes the new price of the appliance. The current appliance is not saved to file as part of this command. The new content of current appliance is displayed in the user’s screen. The new price will be saved when the appliance instance is stored to its file.
5. **s** — Save all appliances. This command save the appliance(s) currently in memory to the corresponding file(s). First, the files are deleted (e.g., using the remove() function). Next, an ofstream instance is opened on the named file, and the appliance’s information is saved to the new file. Finally, the stream is closed.
6. **q** — Quits the appliance manager.

Files:
- Appliance.cpp         - Defenition of class Appliance.
- Appliance.h           - Declaration of class Appliance.
- ApplianceManager.cpp  - Main program.
- AppliancePtr.cpp      - Defenition of AppliancePtr class.
- AppliancePtr.h        - Declaration of AppliancePtr class.
- LinkedList.cpp        - Defenition of LinkedList class.
- LinkedList.h          - Declaration of LinkedList class.
- makefile              - Make file.

Folders:
- Appliances - Stores all appliance files. This folder name is hardcoded in all classes so, if it will be renamed, program will not work correctly.

Appliance files:
- These files are regualar '.txt' files, but has name the same as its appliance ID.For example, if appliance ID is 5, then appliance file will have name '5.txt'. 

Sample file structure:
```    
    Line 1: appliance ID  
    Line 2: appliance type  
    Line 3: manufacturer  
    Line 4: price  
    Line 5 and more: picure's path  
    *Can be more than one image path.  
```
```
    4
    2
    Whirlpool
    349.990000
    /var/www/public_html/images/whirpool_2_1.jpeg
    /var/www/public_html/images/whirpool_2_2.jpeg
    /var/www/public_html/images/whirpool_2_3.jpeg
```

Compilation:
- To compile program, simply run 'make' in the command line.

Run:
- To run program, type './ApplianceManager' or 'make run' in the command line.

Development:
- This application was written in Xcode Version 9.3 on macOS High Sierra 10.13.4.

Tests:
- This application was compiled and tested on macOS environment and on linux virtual machine. Valgrind showed that program deallocated all allocations with 0 errors:
```
    Valgrind output:
    ==28618== HEAP SUMMARY:
    ==28618==     in use at exit: 0 bytes in 0 blocks   
    ==28618==   total heap usage: 1,439 allocs, 1,439 frees, 975,063 bytes allocated
    ==28618== 
    ==28618== All heap blocks were freed -- no leaks are possible
    ==28618== 
    ==28618== For counts of detected and suppressed errors, rerun with: -v
    ==28618== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

