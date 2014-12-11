//****************************************************************************
//
//
//
//****************************************************************************


 
 
// ===========================================================================
//                                   Libraries
// ===========================================================================

#include <cstring>


// ===========================================================================
//                                 Project Files
// ===========================================================================
#include "String.h"




//############################################################################
//                                                                           #
//                           Class String                                    #
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

  data = new char[s_size];

  for(int i=0; i<s_size; i++)
  {
  	data[i] = s[i];
  }

  size = s_size;
  capacity = s_size;

}


String::String(char* cstr)
{

  int i = 0;

  while (cstr[i]!='\0')
  {
    i++;
  }

  printf("i=%d\n",i );

  size = i;
  capacity = size;

  data = new char[size];

  memcpy(data, cstr, size);

  for (int i = 0; i < size; ++i)
  {
    printf("%c\n", data[i] );
  }

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
  delete data;	// ??? /!\ MEMORY LEAK /!\ ???
  size = 0;
  capacity = 0;
  data = NULL;
}





/*
size_t String::size()
{
 return (size*8*sizeof(char));
}*/



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


void String::setCapacity(int c)
{
  capacity = c;

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

  if(new_s < capacity)
    {

      size = new_s;

      for(int i = new_size +1; i<size; i++)
      {
      	data[i]='\0';
      }

    }
  else if(new_s > capacity)
    {
      //create a pointer on a table of char to stock the value of data (because we are going to delete it)
      char* data2 = new char[new_s];

      printf("inter\n");
      for(int i=0; i<size; i++)
      {
        data2[i]=data[i];
        printf("%c %c\n", data2[i], data[i]);
      }

      printf("\n");
      printf("%p\n", data);

      delete [] data;
      
      data= NULL;

      for(int i=size; i<new_s; i++)
      {
      	data2[i]='\0';
      }

      size = new_s;

    }
	

}





String& String::operator+(char c)
{
  
  data[size] = c;
  printf("%c\n", data[size] );
  size += 1;

  return *this;

}






String& String::operator= (char c)
{
  size = 1;
  data [0] = c;		// ??? /!\ MEMORY LEAK /!\ ???
  return *this;
}






String& String::operator= (const String& str)
{
  size = str.getSize();
  for (int i=0; i<size; i++)
    {
      //data[i] = str.at(i);   // TO BE ADDRESSED !!!!
    }
  return *this;
}





// take a string in "" as parameter or a c_str
String& String::operator+(const char* s)
{
  int i = 0;

  while (s[i]!='\0')
  {
    i++;
  }

  //i corresponds to the size of s


  if(size+i<=capacity)
  {
    for(int j = i; j<size+i; j++)
    {
      data[j]=s[j-i];
    }

  }

  else if(size+i>capacity)
  {
    char* s2= new char[size+i];
    memcpy(s2,data,size);

    this->print();
    delete[] data;
    data = NULL;

    for(int j = i; j<size+i; j++)
    {
      s2[j]=s[j-i];
    }

    data = s2;

  }

  size = size + i;
  capacity = size;

  return *this;

}







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
