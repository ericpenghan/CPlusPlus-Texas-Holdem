OBJECTS = card.o deck.o SortedLinkedList.o rank.o pokerhand.o PA2.o
		#(listing your object files here, separated by space)

HEADERS = card.h deck.h SortedLinkedList.h rank.h pokerhand.h
		#(listing all header files here, seperated by spaces)
OBJECTS1 = card.o deck.o SortedLinkedList.o rank.o pokerhand.o testPA2.o
CS216PA2: $(OBJECTS)
	 g++ $^ -o $@
testPA2: $(OBJECTS1)
	g++ $^ -o $@











%.o: %.cpp $(HEADERS)
	 g++ -c $< -o $@


 
clean:
	 rm -i *.o CS216PA2


