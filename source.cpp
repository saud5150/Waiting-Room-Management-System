//Waiting Room Management System
#include<iostream>
using namespace std;
class Patient {
public:
	int ID;

	Patient() {
		ID = 0;
	}
	Patient(int id) {
		ID = id;
	}
};
class Queue {
public:
	int count = 1;
	static const int sizeOfQueue = 50;
	int queue[sizeOfQueue];
	int front = sizeOfQueue - 1;
	int rear = sizeOfQueue - 1;
	void initializeQueue() {
		 front = sizeOfQueue - 1;
		 rear = sizeOfQueue - 1;
		 count = 1;

	}
	bool isEmpty() {
		return front == rear;
	}
	bool isFull() {
		return ((rear+1)%sizeOfQueue == front);
	}
	void RegisterPatient() {//enqueue
		if(isFull())
		cout << "\nThe queue is full.\n";
		
		 
		else if(!isFull())
		{
			cout << "Registering Patient\n";
			Patient* p = new Patient(count);
			
			rear = (rear + 1) % sizeOfQueue;
			queue[rear] = count;
			cout << "\nPatient has been registered with ID: " << count;
			count++;

			if (front == sizeOfQueue - 1) {
				front = (front+1) % sizeOfQueue;
			}
		}
	}
	void ServePatient() {
		if(!isEmpty())
		 {//Check if queue is empty
			front = (front + 1) % sizeOfQueue;
			cout << "\nPatient with ID " << queue[front - 1] << " will be served now\n";
			count--;
			//delete  queue[front];
			
		}
		else {
			cout << "\nThere are no patients.\n";
		}
	}
	void CancelAll() {
		for (int i = front; i <= rear; i++) {
			queue[i] = 0;

		}
		cout << "\nAll appointments cancelled.\n";
		initializeQueue();
	}
	void CanDoctorGoHome() {
		if (isEmpty()) {
			cout << "\nThe doctor can go home.\n";
		}
		else {
			cout << "\nThe doctor cannot go home.\n";
		}
	}
	void ShowAllPatient() {
		if (isEmpty()) {
			cout << "\nQueue is empty.\n"; return;
		}
		for (int i = front; i <= rear; i++) {
			cout << "Patient ID "
				<< queue[i] << endl;
		}
	}
};
int main() {
	cout << "\nWelcome to the Waiting Room!\n";
	//system("pause");
	int option = 0;
	Queue q;
	while (option != 6) {
		cout << "\nPress 1 to Register a Patient\n"
			<< "Press 2 to Serve a Patient\n"
			<< "Press 3 to Cancel All Appointments\n"
			<< "Press 4 to Check Whether the Doctor Can Go Home\n"
			<< "Press 5 to Show All Patients\n";
		cin >> option;

		switch (option) {
		case 1: q.RegisterPatient(); break;
		case 2: q.ServePatient(); break;
		case 3: q.CancelAll(); break;
		case 4: q.CanDoctorGoHome(); break;
		case 5: q.ShowAllPatient(); break;
		case 6: break;
		default:
			cout << "Invalid Entry.";

		}
	}
	return 0;
}
