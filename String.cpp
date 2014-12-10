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


char* String::c_str()
{
  c_data = new char[size+2];
  for(int i=0; i<size; i++)
  {
  	c_data = data[i];
  }
  c_data[size] = '\';
  c_data[size+1] = '0';
  return c_data;
}

int String::getSize()
{
  return size;
}


int String::getCapacity()
{
  return capacity;
}


char* String::getData()
{
  return data;
}

int String::length()
{

  return size;     // peux prendre "toto" en paramètre par exemple ?

}


int String::max_size()
{
  return MAX_SIZE;
}


char String::at(int position)
{
  return data[position -1];
}


//resize the String. If the new size is lower, remove the characters beyond the nth. If bigger, add (new_size - size) null characters
void String::resize(int new_size)
{
  if(new_size < size)
    {
      size = new_size;

      for(int i = new_size +1; i<size; i++)
      {
      	data[i]='0';
      }

    }
  else if(new_size > size)
    {
      size = new_size;

      for(int i=size+1; i<new_size; i++)
      {
      	data[i]=0;
      }

    }
	

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
