#include <iostream>

#include "arraylist.hpp"
#include "duck.hpp"

void outputDucks(const Collections::ICollection<Duck>& duckcollection)
{
	std::cout << "\nThe list contains " << duckcollection.getNumElements() << " ducks.\n";
	auto it = duckcollection.getIterator();
	while(it->current())
	{
		it->current()->quack();
		it->next();
	}
}

int main()
{
	Duck alphaDuck("quack->quack");
	Duck arrayDuck("quackquack");

	// add ducks
	Collections::ArrayList<Duck> arrayList;
	arrayList.insert( alphaDuck );
	for( int i=0; i<5; ++i )
		arrayList.insert( arrayDuck );

	// do some explicit ducking
	arrayList[1].quack();
	arrayList[3].quack();

	// reset an element
	arrayList[3] = Duck("kuckuk!");
	//arrayList.resize(4);

	// output per iterator
	outputDucks(arrayList);
	
	// swap!
	std::cout << "\nClone and swapping\n";
	Collections::ArrayList<Duck> arrayList2( dynamic_cast<Collections::ICollection<Duck>&>( arrayList ) );
	Duck first = arrayList2[0];
	arrayList2[0] = arrayList2[1];
	arrayList2[1] = first;

	// output per loop
	for(unsigned int i=0; i<arrayList2.getNumElements(); ++i)
		arrayList2[i].quack();

	return 0;
}