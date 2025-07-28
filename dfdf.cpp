#include <iostream>
#include <fstream>
#include <sstream>



using namespace std;

class Auth {
public:
    static bool login(string& name, string& userID) {
        string id, password, storedName, inputID, inputPass;
        cout << "\nEnter User ID: ";
        cin >> inputID;
        cout << "Enter Password: ";
        cin >> inputPass;

        ifstream fin("users.txt");
        string line;
        while (getline(fin, line)) {
            stringstream ss(line);
            getline(ss, storedName, '|');
            getline(ss, id, '|');
            getline(ss, password, '|');
            if (id == inputID && password == inputPass) {
                name = storedName;
                userID = id;
                return true;
            }
        }
        return false;
    }

    static void registerUser() {
        string name, id, password;
        cout << "\nEnter Name: ";
        cin >> name;
        cout << "Choose User ID: ";
        cin >> id;
        cout << "Choose Password: ";
        cin >> password;

        ofstream fout("users.txt", ios::app);
        fout << name << "|" << id << "|" << password << "\n";
        fout.close();

        cout << "\u2714 Registration successful!\n";
    }
};


// Abstract Base Class
class User {
protected:
    string name, id;
public:
    User(string n, string i) : name(n), id(i) {}
    virtual void displayMenu() = 0;
    string getID() const { return id; }
    virtual ~User() {}
};
class Chat {
public:
    static void startChat(const string& freelancerID, const string& gigID) {
        string answer;

        cout << "\n💬 Chat with Client (Gig ID: " << gigID << ")\n";
        cout << freelancerID << " is asking:\n";

        cout << "1. Can you please describe your expectations for this gig?\n";
        cout << "Client: ";
        cin.ignore();
        getline(cin, answer);

        cout << "2. What is the deadline for this project?\n";
        cout << "Client: ";
        getline(cin, answer);

        cout << "3. Will there be any reference files or materials provided?\n";
        cout << "Client: ";
        getline(cin, answer);

        cout << "\n✅ Thanks for the information! Freelancer will begin reviewing your responses.\n";
    }
};



// Gigs Class (File-Based)
class Gig {
public:
    static void postGig() {
        string gigID, title, desc, niche;
        double price;
        cin.ignore();
        cout << "\nEnter Gig ID: "; getline(cin, gigID);
        cout << "Enter Title: "; getline(cin, title);
        cout << "Enter Description: "; getline(cin, desc);
        cout << "Enter Niche (e.g., Logo, Writing): "; getline(cin, niche);
        cout << "Enter Price: "; cin >> price;

        ofstream fout("gigs.txt", ios::app);
        fout << gigID << "|" << title << "|" << desc << "|" << niche << "|" << price << "\n";
        fout.close();

        cout << " Gig Posted Successfully!\n";
    }

    static void viewGigs() {
        ifstream fin("gigs.txt");
        string line;
        cout << "\n Available Gigs:\n";
        while (getline(fin, line)) {
            stringstream ss(line);
            string gigID, title, desc, niche, price;
            getline(ss, gigID, '|');
            getline(ss, title, '|');
            getline(ss, desc, '|');
            getline(ss, niche, '|');
            getline(ss, price, '|');

            cout << "---------------------------------\n";
            cout << "ID: " << gigID << "\nTitle: " << title << "\nNiche: " << niche << "\nPrice: $" << price << "\n";
        }
        fin.close();
    }
    static void searchByGigID() {
        string searchGigID;
        cout << "Enter Gig ID to search: ";
        cin >> searchGigID;
        ifstream fin("gigs.txt");
        string line;
        bool found = false;

        cout << "\n Matching Gigs:\n";
        while (getline(fin, line)) {
            stringstream ss(line);
            string gigID, title, desc, niche, price;
            getline(ss, gigID, '|');
            getline(ss, title, '|');
            getline(ss, desc, '|');
            getline(ss, niche, '|');
            getline(ss, price, '|');

            if (gigID == searchGigID) {
                found = true;
                cout << "---------------------------------\n";
                cout << "ID: " << gigID << "\nTitle: " << title << "\nPrice: $" << price << "\n";
            }
        }
        if (!found) cout << "No gigs found for ID: " << searchGigID << "\n";
        fin.close();
    }

   static void searchByNiche() {
    string searchNiche;
    
    cout << "Enter niche to search (case-insensitive)(Logo Design,Blog Writing,Website Development,Social Media Marketing,Video Editing are available): ";
    getline(cin >> ws, searchNiche);  
    
    ifstream fin("gigs.txt");
    string line;
    bool found = false;

    cout << "\n Matching Gigs:\n";
    while (getline(fin, line)) {
        stringstream ss(line);
        string gigID, title, desc, niche, price;
        getline(ss, gigID, '|');
        getline(ss, title, '|');
        getline(ss, desc, '|');
        getline(ss, niche, '|');
        getline(ss, price, '|');

        if (niche == searchNiche) {
            found = true;
            cout << "---------------------------------\n";
            cout << "ID: " << gigID << "\nTitle: " << title << "\nPrice: $" << price << "\n";
        }
    }
    if (!found) cout << "No gigs found for niche: " << searchNiche << "\n";
    fin.close();
}
    static void applyToGig(string ClientID) {
    string gigID;
    cout << "Enter Gig ID to apply: ";
    cin >> gigID;

    // Open gigs.txt to find gig details by gigID
    ifstream fin("gigs.txt");
    string line;
    bool found = false;
    string title, desc, niche;
    double price = 0.0;
    

    while (getline(fin, line)) {
        stringstream ss(line);
        string currentGigID, currentTitle, currentDesc, currentNiche, currentPriceStr;

        getline(ss, currentGigID, '|');
        getline(ss, currentTitle, '|');
        getline(ss, currentDesc, '|');
        getline(ss, currentNiche, '|');
        getline(ss, currentPriceStr, '|');

    }
    fin.close();

    if (!found) {
        cout << " Gig ID not found! Application failed.\n";
        return;
    }

    // Now write the application with full gig info
    ofstream fout("applications.txt", ios::app);
    fout << ClientID << "|" << gigID << "|" << title << "|" << niche << "|" << price << "\n";
    fout.close();

    cout << " Application Submitted Successfully!\n";
    
    Chat::startChat(ClientID, gigID);
}

};

// Review Class
class Review {
public:
    static void leaveReview(string clientID) {
        string freelancerID, gigID, comment;
        int rating;

        cin.ignore();
        cout << "Enter Freelancer ID to review: ";
        getline(cin, freelancerID);
        cout << "Enter Gig ID: ";
        getline(cin, gigID);
        cout << "Enter rating (1-5): ";
        cin >> rating;
        cin.ignore();
        cout << "Enter comment: ";
        getline(cin, comment);

        ofstream fout("reviews.txt", ios::app);
        fout << freelancerID << "|" << clientID << "|" << gigID << "|" << rating << "|" << comment << "\n";
        fout.close();

        cout << " Review submitted successfully!\n";
    }

    static void viewReviews(string freelancerID) {
        ifstream fin("reviews.txt");
        string line;
        int count = 0, sum = 0;

        cout << "\n Reviews for Freelancer ID: " << freelancerID << "\n";
        while (getline(fin, line)) {
            stringstream ss(line);
            string fID, cID, gID, ratingStr, comment;
            getline(ss, fID, '|');
            getline(ss, cID, '|');
            getline(ss, gID, '|');
            getline(ss, ratingStr, '|');
            getline(ss, comment, '|');

            if (fID == freelancerID) {
                int rating;
                cout << "Gig: " << gID << ", Rating: " << rating << ", Comment: " << comment << "\n";
                sum += rating;
                count++;
            }
        }
        fin.close();

        if (count > 0)
            cout << "Average Rating: " << (double)sum / count << "/5\n";
        else
            cout << "No reviews yet.\n";
    }
};
class ApplicationManager {
public:
    static void viewApplicationsForGig(const string& gigID) {
        ifstream fin("applications.txt");
        string line;
        bool found = false;

        cout << "\nApplications for Gig ID: " << gigID << "\n";
        while (getline(fin, line)) {
            stringstream ss(line);
            string clientID, appGigID, title, niche, price;
            getline(ss, clientID, '|');
            getline(ss, appGigID, '|');
            getline(ss, title, '|');
            getline(ss, niche, '|');
            getline(ss, price, '|');

            if (appGigID == gigID) {
                found = true;
                cout << "Client ID: " << clientID << ", Title: " << title << ", Niche: " << niche << ", Price: $" << price << "\n";
            }
        }
        if (!found) cout << "No applications found for this Gig.\n";
    }
};

// Payment Class
class Payment {
public:
    static void makePayment(string clientID) {
        string freelancerID, gigID;
        double amount;
        cin.ignore();
        cout << "Enter Freelancer ID to pay: ";
        getline(cin, freelancerID);
        cout << "Enter Gig ID: ";
        getline(cin, gigID);
        cout << "Enter amount to pay: ";
        cin >> amount;

        ofstream fout("payments.txt", ios::app);
        fout << freelancerID << "|" << clientID << "|" << gigID << "|" << amount << "|paid\n";
        fout.close();

        cout << " Payment recorded successfully!\n";
    }

    static void viewPayments(string freelancerID) {
        ifstream fin("payments.txt");
        string line;
        double total = 0;
        cout << "\n Payment History for Freelancer ID: " << freelancerID << "\n";
        while (getline(fin, line)) {
            stringstream ss(line);
            string fID, cID, gID, amountStr, status;
            getline(ss, fID, '|');
            getline(ss, cID, '|');
            getline(ss, gID, '|');
            getline(ss, amountStr, '|');
            getline(ss, status, '|');

            if (fID == freelancerID) {
                double amount;
                cout << "Gig: " << gID << ", Amount: $" << amount << ", Status: " << status << "\n";
                total += amount;
            }
        }
        fin.close();

        cout << "Total Earnings: $" << total << "\n";
    }
};

class PaymentManager {
public:
    static void updatePaymentStatus(const string& freelancerID) {
        string gigID, newStatus;
        cout << "Enter Gig ID to update payment status: ";
        cin >> gigID;
        cout << "Enter new status (pending/paid/refunded): ";
        cin >> newStatus;

        ifstream fin("payments.txt");
        ofstream fout("temp.txt");
        string line;
        bool updated = false;

        while (getline(fin, line)) {
            stringstream ss(line);
            string fID, cID, gID, amount, status;
            getline(ss, fID, '|');
            getline(ss, cID, '|');
            getline(ss, gID, '|');
            getline(ss, amount, '|');
            getline(ss, status, '|');

            if (fID == freelancerID && gID == gigID) {
                fout << fID << '|' << cID << '|' << gID << '|' << amount << '|' << newStatus << "\n";
                updated = true;
            } else {
                fout << line << "\n";
            }
        }
        fin.close(); fout.close();
        remove("payments.txt");
        rename("temp.txt", "payments.txt");

        if (updated) cout << "Payment status updated.\n";
        else cout << "No matching payment found.\n";
    }
};

class GigFilter {
public:
    static void filterByPriceRange(double minPrice, double maxPrice) {
    ifstream fin("gigs.txt");
    string line;
    bool found = false;

    cout << "\nGigs between $" << minPrice << " and $" << maxPrice << ":\n";
    while (getline(fin, line)) {
        stringstream ss(line);
        string gigID, title, desc, niche, priceStr;
        getline(ss, gigID, '|');
        getline(ss, title, '|');
        getline(ss, desc, '|');
        getline(ss, niche, '|');
        getline(ss, priceStr, '|');
        
        double price ;  // Remove the previous declaration
        if (price >= minPrice && price <= maxPrice) {
            found = true;
            cout << "ID: " << gigID << ", Title: " << title << ", Price: $" << price << "\n";
        }
    }
    if (!found) cout << "No gigs found in this price range.\n";
}
};




// Client Class
class Client : public User {
public:
    Client(string n, string i) : User(n, i) {}

    void displayMenu() override {
        int choice;
        do {
            cout << "\n Client Menu (" << name << ")\n";
            cout << "1. View All Gigs\n";
            cout << "2. Search Gigs by Niche\n";
            cout << "3. Search Gigs by GigID\n";
            cout << "4. Filter Gigs by Price Range\n";
            cout << "5. Apply to a Gig\n";
            cout << "6. Do Payments\n";
            cout<<  "7. Give review\n";
            cout << "0. Logout\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1: Gig::viewGigs(); break;
                case 2: Gig::searchByNiche(); break;
                case 3: Gig::searchByGigID(); break;
                case 4: {
                    double minP, maxP;
                    cout << "Enter minimum price: "; cin >> minP;
                    cout << "Enter maximum price: "; cin >> maxP;
                    GigFilter::filterByPriceRange(minP, maxP);
                    break;
                }
                case 5: Gig::applyToGig(id); break;
                case 6: Payment::makePayment(id); break;
                case 7: Review::leaveReview(id); break;
                case 0: cout << "Logging out...\n"; break;
                default: cout << "Invalid choice.\n";
            }
        } while (choice != 0);
    }
};

// Freelancer Class
class Freelancer : public User {
public:
   Freelancer(string n, string i) : User(n, i) {}

    void displayMenu() override {
        int choice;
        do {
            cout << "\n Freelancer Menu (" << name << ")\n";
            cout << "1. Post a New Gig\n";
            cout << "2. View All Gigs\n";
            cout << "3. View Applications for a Gig\n";
            cout << "4. View My Reviews\n";
            cout << "5. View My Payments\n";
            cout << "6. Update Payment Status\n";
            cout << "0. Logout\n";
            
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1: Gig::postGig(); break;
                case 2: Gig::viewGigs(); break;
                case 3: {
                    string gigID;
                    cout << "Enter Gig ID to view applications: ";
                    cin >> gigID;
                    ApplicationManager::viewApplicationsForGig(gigID);
                    break;
                }
                case 4: Review::viewReviews(id); break;
                case 5: Payment::viewPayments(id); break;
                case 6: PaymentManager::updatePaymentStatus(id); break;
                case 0: cout << "Logging out...\n"; break;
                default: cout << "Invalid choice.\n";
            }
        } while (choice != 0);
    }
};

// Main Program

int main() {
    int mainChoice;
    do {
        cout << "===============================\n";
        cout << " Welcome to Freelance Platform \n";
        cout << "===============================\n";
        cout << "1. Register\n2. Login\n0. Exit\nChoice: ";
        cin >> mainChoice;

        if (mainChoice == 1) {
            Auth::registerUser();
        }
        else if (mainChoice == 2) {
        int roleChoice;
        cout << "\nLogin as:\n1. Client\n2. Freelancer\nChoice: ";
        cin >> roleChoice;
        if (roleChoice != 1 && roleChoice != 2) {
            cout << "Invalid choice. Please try again.\n";
            continue;
        }
        

            string name, id;
            if (Auth::login(name, id)) {
                User* user ;
                if (roleChoice == 1) user = new Client(name, id);
                else if (roleChoice == 2) user = new Freelancer(name, id);
                else {
                    cout << "Invalid role. Exiting login.\n";
                    continue;
                }

                cout << "\nWelcome, " << name << " (" << id << ")!\n";
                user->displayMenu();
                delete user;
            } else {
                cout << "Login failed. Invalid credentials.\n";
            }
        }
        else if (mainChoice == 0) {
            cout << "Goodbye!\n";
        }
        else {
            cout << "Invalid option.\n";
        }
    } while (mainChoice != 0);

    return 0;
}
