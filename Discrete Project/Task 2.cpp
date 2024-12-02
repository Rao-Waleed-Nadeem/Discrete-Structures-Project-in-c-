//#include <iostream>
//#include <vector>
//#include <cmath>
//#include <string>
//#include<stack>
//
//using namespace std;
//
//class base {
//    string id;          
//    vector<int> v;       
//public:
//    base() {};
//    base(string ID, vector<int> temp) : id(ID), v(temp) {}
//
//    void display() {
//        cout << "Variable: \n" << id << " | Truth values: \n";
//        for (int value : v) {
//            cout << value << " ";
//        }
//        cout << endl;
//    }
//    string getId() { return id; }
//    vector<int>getTable() { return v; }
//    void setId(string Id) { id = Id; }
//    void setTable(vector<int>vec) { v = vec; }
//    vector<int> invertTable() {
//        vector<int>temp = v;
//        for (int i = 0; i < temp.size(); i++) {
//          temp[i] = (temp[i] == 0) ? 1 : 0;
//        }
//        return temp;
//    }
//    vector<int>AND(vector<int>v1,vector<int>v2){
//        vector<int>temp;
//        for (int i = 0; i < v1.size(); i++) {
//            if (v1[i] == 1 && v2[i] == 1)
//                temp.push_back(1);
//            else
//                temp.push_back(0);
//        }
//        return temp;
//    }
//    vector<int>OR(vector<int>v1, vector<int>v2) {
//        vector<int>temp;
//        for (int i = 0; i < v1.size(); i++) {
//            if (v1[i] == 1 || v2[i] == 1)
//                temp.push_back(1);
//            else
//                temp.push_back(0);
//        }
//        return temp;
//    }
//    vector<int>IMPLIES(vector<int>v1, vector<int>v2) {
//        vector<int>temp;
//        for (int i = 0; i < v1.size(); i++) {
//            if (v1[i] == 1 && v2[i] == 0)
//                temp.push_back(0);
//            else
//                temp.push_back(1);
//        }
//        return temp;
//    }
//    vector<int>BICONDITIONAL(vector<int>v1, vector<int>v2) {
//        vector<int>temp;
//        for (int i = 0; i < v1.size(); i++) {
//            if (v1[i] == v2[i])
//                temp.push_back(1);
//            else
//                temp.push_back(0);
//        }
//        return temp;
//    }
//};
//
//class binaryData {
//    vector<base> data;
//    int size = 0;
//public:
//    binaryData():size(0),data(){}
//    void push_back(const base& b) {
//        data.push_back(b);
//    }
//
//    void display() {
//        for (int i = 0; i < data.size();i++) {
//            if(data[i].getId()!="1"&&data[i].getId()!="0"){ data[i].display(); }
//        }
//    }
//
//    void makingStructure(string s) {
//      
//        string temp = "";
//        int countVar = 0;
//
//        for (int i = 0; i < s.length(); i++) {
//            if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) {
//                // Check if character already exists in 'temp'
//                if (temp.find(s[i]) == string::npos) {  // If character is not found in 'temp'
//                    temp += s[i];                       // Add character to 'temp'
//                    ++countVar;                         // Increment countVar
//                }
//            }
//        }
//
//
//         int total = pow(2, countVar);
//         size = total;
//         int divide = total;
//        for (int i = 0; i < countVar; i++) {
//            vector<int> temp1;
//
//            divide /= 2;
//            int a = 1;
//            for (int j = 0; j < total; j++) {
//                if (j % divide == 0) {
//                    a = (a == 1) ? 0 : 1;
//                }
//                temp1.push_back(a);
//            }
//
//             base temp2(string(1, temp[i]), temp1);
//             
//            data.push_back(temp2);  
//        }
//        vector<int>temp1(size, 1);
//        vector<int>temp0(size, 0);
//        data.push_back({ "1",temp1 });
//        data.push_back({ "0",temp0 });
//        display();
//    }
//
//    base applyOperation(char ch,base first,base second) {
//        base temp;
//        temp.setId(first.getId() +  ch + second.getId());
//        switch (ch) {
//        case '&':
//            temp.setTable(temp.AND(first.getTable(), second.getTable()));
//            break;
//        case '|':
//            temp.setTable(temp.OR(first.getTable(), second.getTable()));
//            break;
//        case '>':
//            temp.setTable(temp.IMPLIES(first.getTable(), second.getTable()));
//            break;
//        case '^':
//            temp.setTable(temp.BICONDITIONAL(first.getTable(), second.getTable()));
//            break;
//        }
//        return temp;
//    }
//
//    base evaluateString(string s) {
//        vector<int >temp;
//        stack<base> res;
//        stack<char> stk;
//        bool isNext = false;
//        for (int i = 0; i < s.length(); i++) {
//            isNext = false;
//            if (s[i] == '(')
//                stk.push(s[i]);
//            if (s[i] == '!') {
//                if (s[i + 1] == '(') {
//                    stk.push(s[i]);
//                }
//                else {
//                    for (int j = 0; j < data.size(); j++) {
//                        if (string(1, s[i+1]) == data[j].getId()) {
//                            vector<int>t1 = data[j].getTable();
//                            for (int k = 0; k < t1.size(); k++) {
//                                if (t1[k] == 1)t1[k] = 0;
//                                else t1[k] = 1;
//                            }
//                            base b("!"+string(1,s[i+1]), t1);
//                            i++;
//                            cout << b.getId();
//                            res.push(b);
//                            isNext = true;
//                            break;
//                        }
//                    }
//                   
//                }
//            }
//            if (s[i] == ')') {
//                while (stk.top() != '(') {
//                base second = res.top();
//                res.pop();
//                base first = res.top();
//                cout << endl;
//                //first.display();
//               
//                //second.display();
//               
//
//                
//                res.pop();
//                base temp = applyOperation(stk.top(), first, second);
//                temp.setId("(" + temp.getId() + ")");
//                temp.display();
//                cout << endl;
//                res.push(temp);
//                cout << endl;
//                stk.pop();
//                }
//                stk.pop();
//            }
//            if (s[i] == '&' || s[i] == '|' || s[i] == '>' || s[i] == '^') {
//                stk.push(s[i]);
//            }
//            if ((s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z' || s[i]=='1'||s[i]=='0') && isNext == false) {
//                for (int j = 0; j < data.size(); j++) {
//                    if (data[j].getId() == string(1, s[i])) {
//                        res.push(data[j]);
//                    }
//                }
//            }
//        }
//        while (!stk.empty()) {
//
//            base b;
//            base second = res.top();
//            res.pop();
//            if (stk.top() != '!') {
//                base first = res.top();
//                res.pop();
//                res.push(applyOperation(stk.top(), first, second));
//           }
//            else {
//                vector<int>t1 = second.getTable();
//                for (int i = 0; i < t1.size(); i++) {
//                    t1[i] =( t1[i] == 0) ? 1 : 0;
//                }
//                string str = second.getId();
//               
//                res.push({str, t1});
//            }
//            stk.pop();
//        }
//      
//        cout << "\nFinal Result\n\n";
//        res.top().display();
//        return res.top();
//    }
//
//};
//
//bool compareBoth(base b,base c) {
//    return b.getTable() == c.getTable();
//}
//
//
//
//bool validString(string s) {
//    if (s.length() == 0)return false;
//    if (s[0] == '^' || s[0] == '&' || s[0] == '>' || s[0] == '|')return false;
//    stack<bool>bracket;
//    bool isOperator = false;
//    for (int i = 0; i < s.length(); i++) {
//        if (s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z' || s[i]==1||s[i]==0) {
//           
//            if (s[i + 1] == '(')return false;
//            if (s[i + 1] >= 'a' && s[i + 1] <= 'z' || s[i + 1] >= 'A' && s[i + 1] <= 'Z' || s[i] == 1 || s[i] == 0)return false;
//            isOperator = false;
//        }
//        else if(s[i]=='('){
//            if (i != s.length() - 1) {
//                if (s[i + 1]==')')return false;
//                if (s[i + 1] == '^' || s[i + 1] == '&' || s[i + 1] == '>' || s[i + 1] == '|' )return false;
//            }
//            bracket.push(1);
//            isOperator = false;
//        }
//        else if (s[i] == ')') {
//            if (i != s.length() - 1) {
//                if (s[i + 1] == '(')return false;
//            }
//            if (bracket.empty())return false;
//            bracket.pop();
//            isOperator = false;
//        }
//        else if(s[i]=='!') {
//            if (i == s.length() - 1)return false;
//            if (s[i + 1] == ')')return false;
//            if (s[i + 1] == '^' || s[i + 1] == '&' || s[i + 1] == '>' || s[i + 1] == '|' || s[i+1]=='!')return false;
//            isOperator = false;
//        }
//        else if (s[i] == '^' || s[i] == '&' || s[i] == '>' || s[i] == '|') {
//            if (i == s.length() - 1)return false;
//            if (s[i + 1] == '^' || s[i + 1] == '&' || s[i + 1] == '>' || s[i + 1] == '|'||s[i+1]==')')return false;
//            isOperator = true;
//        }
//    }
//    return (bracket.empty());
//}
//
//void displayMenu() {
//    cout << "\n==== Logical Statement Validator ====\n";
//    cout << "1. Enter and Compare Two Logical Statements\n";
//    cout << "2. Exit\n";
//    cout << "======================================\n";
//    cout << "Enter your choice: ";
//}
//
//void getLogicalStatement(string& statement) {
//    do {
//        cout << "Enter logical statement (e.g., 'A AND B'): ";
//        getline(cin, statement); // Use getline to handle spaces
//        if (!validString(statement)) {
//            cout << "Invalid logical statement. Please try again.\n";
//        }
//    } while (!validString(statement));
//}
//
//bool isValidChoice(const string& choice) {
//    if (choice.length() == 0)return false;
//    return choice == "1" || choice == "2";
//}
//
//int main() {
//    string choice;
//    do {
//        displayMenu();
//        getline(cin, choice); // Get the entire choice as a string
//
//        if (!isValidChoice(choice)) {
//            cout << "Invalid choice. Please select a valid option.\n";
//            continue;
//        }
//
//        if (choice == "1") {
//            string s1, s2;
//
//            cout << "\n--- Enter First Logical Statement ---\n";
//            getLogicalStatement(s1);
//
//            cout << "\n--- Enter Second Logical Statement ---\n";
//            getLogicalStatement(s2);
//
//            binaryData BD1, BD2;
//            BD1.makingStructure(s1);
//            base b1 = BD1.evaluateString(s1);
//
//            BD2.makingStructure(s2);
//            base b2 = BD2.evaluateString(s2);
//
//            cout << "\n\n--- Comparison Result ---\n";
//            if (compareBoth(b1, b2)) {
//                cout << "Both statements are logically equal.\n";
//            }
//            else {
//                cout << "Both statements are not logically equal.\n";
//            }
//            cout << "--------------------------\n";
//        }
//        else if (choice == "2") {
//            cout << "Exiting program. Goodbye!\n";
//        }
//    } while (choice != "2");
//
//    return 0;
//}