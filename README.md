# -Cplusplus-Program
**Summarize the project and what problem it was solving.**


  This project is intended to accept a text file with a list of grocery items then organize this data. Once the data is organized into a map, a new file is   created and the organized map is output into the new file. Finally, the user is prompted with 4 options which will provide the user access to the           information, the first option returns the count for the item the user enters, and options 2 and 3 print the map with either the counts or a histogram for   the counts. Option 4 terminates the program.
  
  
**What did you do particularly well?**


  What I am proudest of in this particular project was my ability to write as little code into main.cpp as possible. My actual goal was to only have 1       line, being the call for CreateGroceryInventory() which would itself call MainMenu() which calls the other functions as needed. I was not able to go       quite that extreme, but I am pleased with what I was able to do regardless.
  
  
**Where could you enhance your code? How would these improvements make your code more efficient, secure, and so on?**


  I initially had my functions all set to static so that I could call everything without having to create a new object. I wanted to do this as a way to       reduce the lines of code in main.cpp, and to avoid clogging the memory by creating new objects. I would make this change, the reason I changed it was       because I was getting errors that I couldn't solve without creating the new object. I would fix this.
  
  
**Which pieces of the code did you find most challenging to write, and how did you overcome this? What tools or resources are you adding to your support network?**


  The hardest part for me was the beginning. I could open, read (or write to) and close the files just fine, but organizing the read in data was a           struggle. I have been getting a lot of tutoring which has been very helpful and it was one of the tutors who helped me with this. Initially I was trying   to create a vector then organize from there, which I think would have been perfectly fine, but I was struggling with. My tutor walked me through creating   a map instead which would organize the items with the counts so that the next steps would be even easier than they would have with the vector.
  
  
**What skills from this project will be particularly transferable to other projects or course work?**


  I think learning to pick the correct container for the data will be very helpful. In this case my attempts to organize the data were made much easier by   picking a more appropriate continer, the map vs a vector. I am also getting better at identifying the errors and how to fix them which will make           troubleshooting easier. Finally, I think my code creativity is getting better. With each project I found that I was quicker to come up with an idea for     the layout of the code.
  
  
**How did you make this program maintainable, readable, and adaptable?**


  I made sure to utilize 3 separate files to make my code. I used a header file to declare all the public and private members, the Grocery.cpp file which     actually contains the various functions, and the Main.cpp which only contained the calls to drive the code in Grocery.cpp. 
