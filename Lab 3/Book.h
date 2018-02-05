#include <iostream>
#include <iomanip>
#include <string.h>

using namespace std;
class Book 
{
  public: 
    char title[256];
    char author[64];
    float price;
    void show_title(void) { cout << title << '\n'; };
    float get_price(void) { return(price); };
    void show_book(void); 
    void assign_publisher(char *name) { strcpy(publisher, name); };
  private:
    char publisher[256];
    void show_publisher(void) { cout << publisher << '\n'; };
};

void Book::show_book(void) 
{ 
    show_title(); 
    show_publisher(); 
};
  
int main(void)
{
   Book tips, diary; 
  
   strcpy(tips.title, "C");
   strcpy(tips.author, "D");
   tips.price = 49.95;
   tips.assign_publisher("E");
   
   strcpy(diary.title, "F");
   strcpy(diary.author, "G");
   diary.price = 9.95;
   diary.assign_publisher("None");

   tips.show_book();
   diary.show_book();
}