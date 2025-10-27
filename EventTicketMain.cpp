#include <iostream> 
#include <string>

// TO DO: #include any other libraries you need

#include <limits>              
#include "EventTicket340.h"
#include "Organizer.h"
#include "VirtualEvent.h" 
#include "Organizer.h"
#include "VenueEvent.h"
#include "Event.h"

using namespace std;

/** 
 * 
 * Displays the application's main menu
 * pre create a new object of type Organizer
 * @param organizer object to interact with
 * 
 * */
static void flushLine() {
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}


void displayOrganizerMenu(Organizer& organizer)
{
	int organizerChoice = 0;
	do {
		cout << "\n Hi, "<< organizer.getUsername() <<", what would you like to do:\n"
		<< "1. Display Profile\n"
		<< "2. Modify Password\n"
		<< "3. Create Event\n"
		<< "4. Display All Events\n"
		<< "5. Display Kth Event\n"
		<< "6. Modify Event\n"
		<< "7. Sell Tickets\n"
		<< "8. Delete Event\n"
		<< "0. Logout\n"
		<< "Choice: ";
		cin >> organizerChoice;
		 if (!cin) { flushLine(); organizerChoice = -1; }

		switch (organizerChoice) {
			case 1:{
				// TO DO: display organizer's profile information
				//      : e.g. organizer.displayProfile();
				organizer.displayProfile();
				break;
			}
			case 2: {
				// TO DO: ask for new password and update organizer's password
				cout << "Enter new password: ";
                string newPw; cin >> newPw;
                organizer.setPassword(newPw);
                cout << "Password updated.\n";
				break;
			}
			case 3: {
				// TO DO: ask organizer to choose event type, then ask them to input event details.
				// Create the event and add it to the organizer's events
				 cout << "Choose event type (1 = Virtual, 2 = Venue): ";
				int t; cin >> t; flushLine();

				string name, desc; double rating = 0.0;
				cout << "Event name: "; getline(cin, name);
				cout << "Description: "; getline(cin, desc);
				cout << "Rating (0..5): "; cin >> rating; flushLine();

				Event* newEvent = nullptr;
				if (t == 1) {
					string url;
					cout << "Enter URL: "; getline(cin, url);
					newEvent = new VirtualEvent(name, desc, rating, url);
				} else if (t == 2) {
					string address; int cap;
					cout << "Enter Address: "; getline(cin, address);
					cout << "Enter Capacity: "; cin >> cap; flushLine();

					newEvent = new VenueEvent(name, desc, rating, address, cap);
				} else {
					cout << "Invalid event type.\n";

					break;
				}

				// If an event was created, add it to the organizer
				if (newEvent) {
					organizer.addEvent(newEvent);
					cout << "Event created.\n";
				}

				break;
			}

			case 4:{
				//        You may re-use code from class demo
				  organizer.displayAllEvents();
				
				break;
			}
			case 5: {
				// TO DO: ask the organizer for a value k
				// Find the Kth event, if k > LinkedBag size, 
				//    return an error message that includes the size of the LinkedBag
				 cout << "Enter k (0-based): ";
                int k; cin >> k; flushLine();
                Event* e = organizer.getKthEvent(k);          
                if (e) {
                    cout << "Kth Event (k=" << k << "):\n";
                    e->display();
                } else {
                    cout << "Invalid index. Current #events: " << organizer.getEventsSize() << "\n";
                }
				break;
			}
			case 6: {
				// TO DO: ask the organizer for the index of the event they want to modify.
				// Find the event, then prompt them for the new name and description.
				// Modify the event accordingly. 
				// If index > LinkedBag size, 
				//    return an error message that includes the size of the LinkedBag
				cout << "Enter event index to modify (0-based): ";
                int idx; cin >> idx; flushLine();
                Event* e = organizer.getKthEvent(idx);
                if (!e) {
                    cout << "Invalid index. Current #events: " << organizer.getEventsSize() << "\n";
                    break;
                }
                string n, d;
                cout << "New name: ";        getline(cin, n);
                cout << "New description: "; getline(cin, d);
                e->setName(n);
                e->setDescription(d);
                cout << "Event updated.\n";
				break;
			}
			case 7: {
				// TO DO: ask the organizer for the index of the event 
				// Find the event, then sell the tickets. 
				// If index > LinkedBag size, 
				//    return an error message that includes the size of the LinkedBag
				cout << "Enter event index to sell tickets for (0-based): ";
                int idx; cin >> idx; flushLine();
                Event* e = organizer.getKthEvent(idx);
                if (!e) {
                    cout << "Invalid index. Current #events: " << organizer.getEventsSize() << "\n";
                    break;
                }
                cout << "Quantity: ";
                int q; cin >> q; flushLine();
                cout << e->sellTicket(q) << "\n";
				break;
			}
			case 8:{
				// TO DO: ask the organizer for the index of the event they want to delete 
				// Find the event, then remove it from the list. 
				// If index > LinkedBag size, 
				//    return an error message that includes the size of the LinkedBag
				 cout << "Enter event name to delete: ";
                string nm; flushLine(); getline(cin, nm);
                bool ok = organizer.removeEventByName(nm);
                cout << (ok ? "Deleted.\n" : "Not found.\n");
				break;
			}
			case 0: {
				cout << "Logging you out." << endl;
				break;
			}
			default:
				cout << "Invalid choice. Please try again." << endl;
		}

	} while (organizerChoice != 0);
}

int main(){
	// Instantiating the program using the default constructor
	// With this implementation, the application will only have one organizer
	EventTicket340 eventTicket340; 

	cout << "\n Welcome to EventTicket340:" << endl;
	// TO DO: Ask the organizer to enter their information 
	//        Instantiate a new Organizer object
	 string username, email, password, bio, picture;
    cout << "Username: ";         getline(cin, username);
    cout << "Email: ";            getline(cin, email);
    cout << "Password: ";         getline(cin, password);
    cout << "Short bio: ";        getline(cin, bio);
    cout << "Profile picture: ";  getline(cin, picture);


	// call eventTicket340 createOrganizer function 
	// replace /*...*/ with the right parameters
	eventTicket340.createOrganizer(std::move(username), std::move(email), std::move(password), std::move(bio), std::move(picture));
	

	// Retrieve the organizer 
	auto& currentOrganizer = eventTicket340.getOrganizer();

	// Display the main menu
	displayOrganizerMenu(currentOrganizer);
	return 0;
}
