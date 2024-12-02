//#include<iostream>
//#include<string>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//class sets {
//	vector<int>v1;
//	vector<int>v2;
//public:
//	sets(){}
//    void createSet1() {
//        int size = -1;
//        while (size < 0) {
//            cout << "Enter size of set 1 (>= 0): ";
//            cin >> size;
//            if (size < 0) {
//                cout << "Size cannot be negative. Please enter a non-negative value." << endl;
//            }
//        }
//
//        for (int i = 0; i < size; i++) {
//            int element = 0;
//            cout << "Enter element " << i + 1 << ": ";
//            cin >> element;
//            v1.push_back(element);
//        }
//    }
//
//    // Function to create Set 2
//    void createSet2() {
//        int size = -1;
//        while (size < 0) {
//            cout << "Enter size of set 2 (>= 0): ";
//            cin >> size;
//            if (size < 0) {
//                cout << "Size cannot be negative. Please enter a non-negative value." << endl;
//            }
//        }
//
//        for (int i = 0; i < size; i++) {
//            int element = 0;
//            cout << "Enter element " << i + 1 << ": ";
//            cin >> element;
//            v2.push_back(element);
//        }
//    }
//
//    vector<int> unionSets() {
//        vector<int>temp = v2;
//        vector<int> v;
//        for (int i = 0; i < v1.size(); i++) {
//            bool isBoth = false;
//            for (int j = 0; j < temp.size(); j++) {
//                if (v1[i] == temp[j]) {
//                    v.push_back(v1[i]);    
//                    temp.erase(temp.begin() + j);  
//                    isBoth = true;
//                    break;
//                }
//            }
//            if (!isBoth) {   
//                v.push_back(v1[i]);
//            }
//        }
//
//         for (int j = 0; j < temp.size(); j++) {
//            v.push_back(temp[j]);
//         }
//
//        return v;
//    }
//
//    vector<int> intersection() {
//        vector<int> v;
//        for (int i = 0; i < v1.size(); i++) {
//            for (int j = 0; j < v2.size(); j++) {
//                if (v1[i] == v2[j]) {
//                    if (find(v.begin(), v.end(), v1[i]) == v.end()) {
//                        v.push_back(v1[i]);
//                    }
//                    break;  
//                }
//            }
//        }
//        return v;
//    }
//
//    void display() {
//        cout << "First Set: " << endl;
//        if (v1.empty())cout << "Null set\n\n\n";
//        for (int i = 0; i < v1.size(); i++) {
//            cout << v1[i] << " ";
//        }
//        cout << endl << endl << endl;
//        cout << "Second Set:" << endl;
//        if(v2.empty())cout << "Null set\n\n\n";
//        for (int j = 0; j < v2.size(); j++) {
//            cout << v2[j] << " ";
//        }
//        cout << endl << endl << endl;
//    }
//
//    vector<int>A_B() {
//        vector<int>v;
//            bool isBoth = false;
//        for (int i = 0; i < v1.size(); i++) {
//            isBoth = false;
//            for (int j = 0; j < v2.size(); j++) {
//                if (v1[i] == v2[j]) {
//                    isBoth = true;
//                    break;
//                }
//            }
//            if (isBoth) {
//                isBoth = false;
//            }
//            else {
//                v.push_back(v1[i]);
//            }
//        }
//        return v;
//    }
//
//    vector<int>B_A() {
//        vector<int>v;
//            bool isBoth = false;
//        for (int i = 0; i < v2.size(); i++) {
//            isBoth = false;
//            for (int j = 0; j < v1.size(); j++) {
//                if (v2[i] == v1[j]) {
//                    isBoth = true;
//                    break;
//                }
//            }
//            if (isBoth) {
//                isBoth = false;
//            }
//            else {
//                v.push_back(v2[i]);
//            }
//        }
//        return v;
//    }
//
//    long long totalRelations() {
//        if (v1.empty() && v2.empty())return 0;
//        return pow(2, v1.size() * v2.size());
//    }
//
//    void inputPairs(vector<vector<int>>& v) {
//        int size = 0;
//        cout << "Enter size of your relation:\n";
//        cin >> size;
//        for (int i = 0; i < size; i++) {
//            int first = 0, second = 0;
//            cout << "Enter 1st element: \n";
//            cin >> first;
//            cout << "Enter 2nd element: \n";
//            cin >> second;
//            v.push_back({ first,second });
//        }
//    }
//
//    bool reflexive() {
//        vector<vector<int>> v;
//        vector<int> temp;
//
//        inputPairs(v);
//
//         for (int i = 0; i < v.size(); i++) {
//            temp.push_back(v[i][0]);  
//            temp.push_back(v[i][1]);  
//        }
//
//         for (int i = 0; i < temp.size(); i++) {
//            for (int j = i + 1; j < temp.size(); j++) {
//                if (temp[i] == temp[j]) {
//                     temp.erase(temp.begin() + j);
//                    j--;  
//                }
//            }
//         }
//
//         sort(temp.begin(), temp.end());
//        
//
//         for (int i = 0; i < v.size(); i++) {
//             if (v[i][0] == v[i][1]) {   
//                 for (int j = 0; j < temp.size(); j++) {
//                     if (temp[j] == v[i][0]) {
//                         temp.erase(temp.begin() + j);
//                         j--;  
//                         break;   
//                     }
//                 }
//             }
//         }
//         return (temp.empty()) ? true : false;
//    }
//
//    bool symmetric() {
//        vector<vector<int>> v;
//        inputPairs(v);
//
//        for (int i = 0; i < v.size(); i++) {
//            bool isSymmetric = false;
//            if (v[i][0] == v[i][1]) {
//                isSymmetric = true;
//                continue;
//            }
//            for (int j = 0; j < v.size(); j++) {
//                if (i != j) {
//                    if (v[i][0] == v[j][1] && v[i][1] == v[j][0]) {
//                        isSymmetric = true;
//                        break;
//                    }
//                }
//            }
//            if (!isSymmetric) {
//                return false;
//            }
//        }
//        return true;
//    }
//
//
//    bool antiSymmetric() {
//        vector<vector<int>> v;
//        inputPairs(v);
//
//        for (int i = 0; i < v.size(); i++) {
//            for (int j = 0; j < v.size(); j++) {
//                if (i != j && v[i][0] == v[j][1] && v[i][1] == v[j][0]) {
//                    return false;
//                }
//            }
//        }
//        return true;
//    }
//
//
//};
//
//int main()
//{
//    sets s;
//    int choice = 0;
//    bool isCreated = false;
//    do {
//        cout << "\nMenu:\n";
//       if(!isCreated) cout << "1) Create sets\n";
//        cout << "2) Union of two sets\n";
//        cout << "3) Intersection of two sets\n";
//        cout << "4) Print sets\n";
//        cout << "5) A - B\n";
//        cout << "6) B - A\n";
//        cout << "7) Total number of relations using two sets\n";
//        cout << "8) Reflexive Relations\n";
//        cout << "9) Symmetric Relations\n";
//        cout << "10) Anti-symmetric Relations\n";
//        cout << "0) Exit\n";
//        cout << "Enter your choice: ";
//        cin >> choice;
//        
//        switch (choice) {
//        case 1:
//        {
//            if (!isCreated) {
//                cout << "Option 1 selected: Create sets\n";
//                s.createSet1();
//                s.createSet2();
//                cout << "Sets created successfully\n";
//           }
//            isCreated = true;
//        }
//            break;
//        case 2:
//        {
//            cout << "Option 2 selected: Union of two sets\n";
//            vector<int >v;
//            v = s.unionSets();
//            if (v.empty())cout << "Union is null set\n";
//            for (int i = 0; i < v.size(); i++) {
//                cout << v[i] << " ";
//            }
//            cout << endl << endl << endl;
//        }
//            break;
//        case 3:
//        {
//            cout << "Option 3 selected: Intersection of two sets\n";
//            vector<int >v1;
//            v1 = s.intersection();
//            if (v1.empty())cout << "Intersection is null set\n";
//            for (int i = 0; i < v1.size(); i++) {
//                cout << v1[i] << " ";
//            }
//            cout << endl << endl << endl;
//        }
//            break;
//        case 4:
//        {
//            cout << "Option 4 selected: Print sets\n";
//            s.display();
//        }
//            break;
//        case 5:
//        {
//            cout << "Option 5 selected: A - B\n";
//            vector<int>v=s.A_B();
//            if (v.empty())cout << "Null set\n\n";
//            for (int i = 0; i < v.size(); i++) {
//                cout << v[i] << " ";
//            }
//            cout << endl;
//        }
//            break;
//        case 6:
//        {
//            cout << "Option 6 selected: B - A\n";
//            vector<int>v = s.B_A();
//            if (v.empty())cout << "Null set\n\n";
//            for (int i = 0; i < v.size(); i++) {
//                cout << v[i] << " ";
//            }
//            cout << endl;
//        }
//            break;
//        case 7:
//        {
//            cout << "Option 7 selected: Total number of relations using two sets\n";
//            cout << "\n\n\nTotal Relations: " << s.totalRelations() << "\n\n\n";
//        }
//            break;
//        case 8:
//        {
//            cout << "Option 8 selected: Reflexive Relations\n";
//            cout << "Given relation is " << (s.reflexive() ? "Reflexive" : "Not Reflexive"); cout << "\n\n\n";
//        }
//            break;
//        case 9:
//        {
//            cout << "Option 9 selected: Symmetric Relations\n";
//            cout << "Given Relation is " << (s.symmetric() ? "Symmetric" : "Not Symmetric"); cout << "\n\n\n";
//        }
//            break;
//        case 10:
//        {
//            cout << "Option 10 selected: Anti-symmetric Relations\n";
//            cout << "Given Relation is " << (s.antiSymmetric() ? "Anti-Symmetric" : "Not Anti-Symmetric"); cout << "\n\n\n";
//        }
//            break;
//        case 0:
//            cout << "Exiting the program.\n";
//            break;
//        default:
//            cout << "Invalid choice, please try again.\n";
//        }
//    } while (choice != 0);
//
//	system("pause");
//	return 0;
//}