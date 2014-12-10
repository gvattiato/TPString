//****************************************************************************
//
//
//
//****************************************************************************


 
 
// ===========================================================================
//                                   Libraries
// ===========================================================================



// ===========================================================================
//                                 Project Files
// ===========================================================================
#include "String.h"




//############################################################################
//                                                                           #
//                           Class String                            #
//                                                                           #
//############################################################################

// ===========================================================================
//                         Definition of static attributes
// ===========================================================================
const int String::MAX_SIZE = 1000;

// ===========================================================================
//                                  Constructors
// ===========================================================================
String::String(void)
{
  size = 0;
  data = NULL;
  capacity = 0;
}



String::String(int a_size)
{
  size = a_size;
  data = new char[a_size];
  capacity = a_size;     //to be determined
}


String::String(const char* s, int s_size)
{
  for(int i=0; i<s_size; i++)
  {
  	data[i] = s[i];
  }

  size = s_size;
  capacity = s_size;

}



// ===========================================================================
//                                  Destructor
// ===========================================================================
String::~String(void)
{
}

// ===========================================================================
//                                 Public Methods
// ===========================================================================

// Returns a pointer to an array that contains a null-terminated sequence of characters representing the current value of the string object
char* String::c_str()
{
  char* c_data = new char[size+1];
  for(int i=0; i<size; i++)
  {
    c_data[i] = data[i];
  }
  c_data[size] = '\0';
  return c_data;
}

// Erases the contents of the string, which becomes an empty string with a length of 0 characters)
void String::clear()
{
  printf("So far so good!\n");
  printf("ERROR:\t\%s\t\%d",__FILE__,__LINE__);
  //delete [] data;
  data = NULL;		// ??? /!\ MEMORY LEAK /!\ ???
  size = 0;
  capacity = 0;
}

/*
size_t String::size()
{
 return (size*8*sizeof(char));
}*/


// rajouter une methode qui affiche la String ?

int String::getSize() const
{
  return size;
}


int String::getCapacity() const
{
  return capacity;
}


char* String::getData() const
{
  return data;
}

size_t String::length() const
{
  return size*8*sizeof(char);     
}

/*Returns the maximum length the string can reach.
This is the maximum potential length the string can reach due to known system or 
library implementation limitations*/
size_t String::max_size() const
{
  return MAX_SIZE*8*sizeof(char);
}


char& String::at(int position) 
{
  return data[position -1];
}


//resize the String. If the new size is lower, remove the characters beyond the nth. If bigger, add (new_size - size) null characters
void String::resize(size_t new_size)
{
  int new_s = new_size/(8*sizeof(char));

  if(new_s < size)
    {

      size = new_s;

      for(int i = new_size +1; i<size; i++)
      {
      	data[i]='\0';
      }

    }
  else if(new_s > size)
    {
      //create a pointer on a table of char to stock the value of data (because we are going to delete it)
      char* inter = new char[size];

      printf("inter\n");
      for(int i=0; i<size; i++)
      {
        inter[i]=data[i];
        printf("%c %c\n", inter[i], data[i]);
      }

      printf("\n");
      printf("%p\n", data);

      delete [] data;
      
      data= NULL;
     

  
      data = new char[new_s];

      for(int i=0; i<size; i++)
      {
        data[i] = inter[i];
        printf("%c\n",data[i]);
      }

      for(int i=size; i<new_s; i++)
      {
      	data[i]='\0';
      }
      size = new_s;

    }
	

}

/*String& String::operator+= (char c)
{
  size += 1;
  data[size] = c;

  return String;

}*/


void String::print()
{
	for(int i=0; i<size; i++)
	  {
	  	printf("%c", data[i]);
	  }

	 printf("\n");
}



// ===========================================================================
//                                Protected Methods
// ===========================================================================

// ===========================================================================
//                               Non inline accessors
// ===========================================================================
