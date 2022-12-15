#ifndef LUCKYDRAW_CPP
#define LUCKYDRAW_CPP
#include "luckyDraw.h"
#include "stack.cpp"
#include "queue.cpp"

luckyDraw::luckyDraw(int count)
{
	totalCount = count;
}

// populate lane_1 with the given array of winnersId
void luckyDraw::populateQueue(int *winnersId)
{
	for (int i = 0; i < totalCount; i++)
	{
		lane_1.enqueue(winnersId[i]);
	}
}

// populate table_1 with the given array of giftsId
void luckyDraw::populateTable(int *giftsId)
{
	for (int i = 0; i < totalCount; i++)
	{
		table_1.push(giftsId[i]);
	}
}
// reverse the queue keeping the conditions in mind
void luckyDraw::reverseQueue()
{
	// we will make lane_2 which is a queue as a stack
	// then we will pop from lane_2 and push to lane_1

	// adding one by one to lane_2 and bringing added element to head
	while (!lane_1.isEmpty())
	{

		// as a flag we are going to use the lowest integer in std library
		lane_2.enqueue(std::numeric_limits<int>::lowest());
		lane_2.enqueue(lane_1.dequeue());
		while (lane_2.front() != std::numeric_limits<int>::lowest())
		{
			lane_2.enqueue(lane_2.dequeue());
		}
		lane_2.dequeue();
	}

	// now lane_2 is a stack
	// we will pop from lane_2 and push to lane_1
	while (!lane_2.isEmpty())
	{
		lane_1.enqueue(lane_2.dequeue());
	}
}

// transfer the stack keeping the conditions in mind
void luckyDraw::transferStack()
{
	table_2.push(-1); // putting flag in table 2 bottom
	while (true)
	{
		// putting everything-1 from table 1 on to table 2 flag
		while (table_1.length() > 1)
		{
			
			table_2.push(table_1.pop());
		}
		// put bottom item of table_1 in special
		specialVariable = table_1.pop();

		// switch everything back from table 2 to table 1 until the flag
		while (table_2.top() != -1)
		{
			table_1.push(table_2.pop());
		}
		// put the flag from table 2 to table 1 top
		table_1.push(table_2.pop());

		table_2.push(specialVariable); // put special in table 2 top

		if(table_1.length() <= 1 &&table_1.top() == -1){
			table_1.pop();
			return;
		}
	}
}

#endif

// // if the queue is empty, return
// if (lane_1.isEmpty())
// {
//     return;
// }

// // if the queue has only one element, return
// if (lane_1.length() == 1)
// {
//     return;
// }

// // if the queue has two elements, swap them
// if (lane_1.length() == 2)
// {
//     lane_1.enqueue(lane_1.dequeue());
//     return;
// }

// // if the queue has more than two elements, reverse it
// int temp = lane_1.dequeue();
// reverseQueue();
// lane_1.enqueue(temp);

// I AM THE BEST!
// using lane 2 as a buffer
// for loop example
//  lane_2.enqueue(0);
//  for(; lane_2.front() < totalCount; lane_2.enqueue(lane_2.dequeue()+1)){
//      cout << "lane_2.front(): " << lane_2.front() << endl;
//  }

// while loop example
//  lane_2.enqueue(0);
//  while(lane_2.front() < totalCount){
//      cout << "lane_2.front(): " << lane_2.front() << endl;
//      lane_2.enqueue(lane_2.dequeue()+1);
//  }

// now using these special loops we will reverse the queue
//  lane_2.enqueue(0);
//  for(; lane_2.front() < totalCount - 1; lane_2.enqueue(lane_2.dequeue()+1))
//  {
//      lane_1.enqueue(lane_1.dequeue());
//  }
//  lane_2.dequeue();
//  prettyPrintQueue(lane_1);

// depreciating nested loop using queues

// while (lane_2.length() != totalCount)
//     lane_2.enqueue(totalCount - lane_2.length() - 1);
// prettyPrintQueue(lane_2);

// for (; lane_2.length() > 0; lane_2.dequeue())
// {
//     lane_2.enqueue(lane_2.front());
//     lane_2.enqueue(lane_2.dequeue());
//     for(; lane_2.front() > 0; lane_2.enqueue(lane_2.dequeue()-1), lane_2.enqueue(lane_2.dequeue())){
//         lane_2.dequeue();
//     }
// }

// lane_2.enqueue(totalCount);
// for (; lane_2.front() > 0; lane_2.enqueue(lane_2.dequeue() - 1))
// {
//     lane_2.enqueue(lane_2.front());
//     lane_2.enqueue(lane_2.dequeue());

//     for (; lane_2.front() > 0; lane_2.enqueue(lane_2.dequeue() - 1), lane_2.enqueue(lane_2.dequeue()))
//     {
//         cout << lane_2.front() << " ";
//     }
//     lane_2.dequeue();
//     cout << endl;
// }
// cout << endl;

// if the queue is empty, return
// if (lane_1.isEmpty())
// {
//     return;
// }

// // if the queue has only one element, return
// if (lane_1.length() == 1)
// {
//     return;
// }

// // if the queue has two elements, swap them
// if (lane_1.length() == 2)
// {
//     lane_1.enqueue(lane_1.dequeue());
//     return;
// }

// // if the queue has more than two elements, reverse it
// lane_2.enqueue(lane_1.dequeue());
// reverseQueue();
// lane_1.enqueue(lane_2.dequeue());