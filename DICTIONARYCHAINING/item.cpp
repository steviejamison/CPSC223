// filename item.cpp
// authors James Stevenson and Jalen Tacsiat
// username: jstevenson4
// date September 25, 2018
// Implementation of Abstract Data Type Item
//
//   data object: an item which is a texting meaning associated with a texting abbreviation
//   operations: create, destroy, copy, 
//               input, output, assign

#include "item.h"

//allows for input of an item from either the standard input device or a file
//pre input has been opened and readied for the input of
//    a texting abbreviation followed by newline and associated meaning with
//    spaces between words ending with a newline. For example:
//    lol
//    laugh out loud
//
//post rightHandSideItem has been filled with a texting abbreviation and its
//     associated meaning
//usage cin >> myItem;
istream& operator>> (istream& input, Item& rightHandSideItem)
{
	char newline;
	input >> rightHandSideItem.textingAbbreviation;
	input.get(newline);
	getline(input, rightHandSideItem.meaning); // extracts the newline
	return input;
}
 
//allows for the output of an item to the standard output device or a file
//pre rightHandSideItem has been filled with a texting abbreviation and
//    its associated meaning 
//    output has been opened
//post rightHandSideItem has been written to the output device
//     lol	laugh out loud
//     there is a newline after the meaning
//usage  outfile << myItem;
ostream& operator<< (ostream& output, const Item& rightHandSideItem)
{
	output << rightHandSideItem.textingAbbreviation << "\t" << rightHandSideItem.meaning << endl;
	return output;
}

//creates an empty item (texting abbreviation and its associated meaning)
//post Item object is an empty meaning
//usage Item aitem;
Item::Item()
{
	
}

//releases memory for a texting abbreviation and its associated meaning
//pre Item object exists
//post Item object no longer exists, memory has been freed
//usage automatically done at the end of scope
Item::~Item()
{
	
}

//creates a new item and copies the right hand side item into item
//pre rightHandSideItem exists and contains a texting abbreviation and its associated meaning
//post Item object is created and is a copy of rightHandSideItem
//usage  Item myItem(yourItem);
Item::Item(const Item& rightHandSideItem)
{
	textingAbbreviation = rightHandSideItem.textingAbbreviation;
	meaning = rightHandSideItem.meaning;
}

//copies a texting abbreviation and its associated meaning
//pre rightHandSideItem has been assigned a texting abbreviation and its associated meaning
//post Item object has a copy of rightHandSideItem
//usage bitem = aitem;
Item& Item::operator=(const Item& rightHandSideItem)
{
	if (this != &rightHandSideItem)
   {
		textingAbbreviation = rightHandSideItem.textingAbbreviation;
		meaning = rightHandSideItem.meaning;
   }
   return *this;
}

//returns true if the item does not have a texting abbreviation
//false otherwise
//pre Item object exists
//post returns true if item does not have a texting abbreviation
//      false otherwise
//usage myItem.isEmpty();
bool Item::isEmpty()
{
	return (textingAbbreviation.empty());
}

//marks a texting abbreviation and meaning for use when deleting dictionary entries
//pre Item object exists
//post Item textingAbbreviation is "deleted" and meaning is "this has been deleted"
//usage myItem.markIt();
void Item::markIt()
{
	textingAbbreviation = "deleted";
	meaning = "this has been deleted";
}

//checks to see if an item has been marked
//pre Item object exists
//post returns true if Item textingAbbreviation is "deleted" and meaning is 
//     "this has been deleted," false otherwise
bool Item::hasBeenMarked()
{
	return (textingAbbreviation == "deleted" and meaning == "this has been deleted");
}