//#include<iostream>
//#include<string>
//#include<vector>
//#include<stack>
//using namespace std;
//
//
//class set {
//public:
//    int x, y;
//    int weight;
//    set(int s,int e, int w):x(s),y(e),weight(w){}
//    void display() {
//        cout << "(" << x << "," << y << ")" << " weight: " << weight << endl;
//    }
//};
//
//void Input(vector<vector<int>>& v) {
//	int size = 0;
//	cout << "Enter size of Matrix: \n";
//	cin >> size;
//	
//    for (int i = 0; i < size; ++i) { 
//        vector<int> row;          
//        for (int j = 0; j < size; ++j) {  
//            int element;
//            cout << "Element [" << i + 1 << "][" << j + 1 << "]: ";
//            cin >> element;
//            row.push_back(element); 
//        }
//        v.push_back(row); 
//    }
//}
//
//void FindMinimum(vector<vector<int>> v, int& s, int& e) {
//    int temp = 0;
//    for (int i = 0; i < v.size(); i++) {
//        for (int j = i + 1; j < v.size(); j++) { // Start from j = i + 1 to avoid duplicate edges in undirected graph
//            if (temp == 0 && v[i][j] != 0) { // Initialize temp and set indices
//                temp = v[i][j];
//                s = i;
//                e = j; // Correctly set the ending vertex
//            }
//            if (temp != 0 && v[i][j] != 0) { // Compare to find the minimum
//                if (temp > v[i][j]) {
//                    temp = v[i][j];
//                    s = i;
//                    e = j;
//                }
//            }
//        }
//    }
//
//    if (temp == 0) {
//         //If no valid edge is found, reset indices
//        s = -1;
//        e = -1;
//        
//    }
//   
//}
//
//int IndexFromTemp(set temp, vector<int>v) {
//   
//        for (int j = 0; j < v.size(); j++) {
//            if (v[j] != temp.x)return v[j];
//            if (v[j] != temp.y)return v[j];
//        }
//    
//    return -1;
//}
//
//bool PresentPair(vector<set>temp, set s) {
//    for (int i = 0; i < temp.size(); i++) {
//        if (temp[i].x == s.x && temp[i].y == s.y)return true;
//    }
//    return false;
//}
//
//void MatchingPushInTemp(vector<set>&result,int &s,int &e,vector<set>&temps,vector<set>&tempe) {
//    for (int j = 0; j < result.size(); j++) {
//        if (s == result[j].x)temps.push_back(result[j]);
//        else if (s == result[j].y)temps.push_back(result[j]);
//        if (e == result[j].x)tempe.push_back(result[j]);
//        else if (e == result[j].y)tempe.push_back(result[j]);
//    }
//}
//
//bool CheckLoop(vector<set>temps, vector<set>tempe) {
//    for (int i = 0; i < temps.size(); i++) {
//        for (int j = 0; j < tempe.size(); j++) {
//            if (temps[i].x == tempe[j].x && temps[i].y == tempe[j].y)return true;
//        }
//    }
//    return false;
//}
//
//void CheckIndexInResultAndPush(vector<set>&result, int index,vector<set>&temp) {
//    for (int i = 0; i < result.size(); i++) {
//        if (index == result[i].x || index == result[i].y) {
//            if (!PresentPair(temp, result[i])) {
//                temp.push_back(result[i]);
//            }
//        }
//    }
//}
//
//vector <set> CheckKaruskal(vector<vector<int>>v) {
//    vector<set>result;
//    int s = 0, e = 0;
//    for (int i = 0, count = 0;count<v.size()-1 && i < v.size()*v.size(); i++) {
//        e = 0; s = 0;
//
//        FindMinimum(v, s, e);
//
//        if (result.empty() || result.size() < 2) {
//            result.push_back({ s,e,v[s][e] });
//            v[s][e] = 0;
//            count++;
//        }
//        else {
//            vector<set>temps;
//            vector<set>tempe;
//             MatchingPushInTemp(result, s, e, temps, tempe);
//
//            for (int j = 0; j < temps.size(); j++) {
//                CheckIndexInResultAndPush(result, temps[j].x, temps);
//                CheckIndexInResultAndPush(result, temps[j].y, temps);
//            }
//
//            for (int j = 0; j < tempe.size(); j++) {
//                CheckIndexInResultAndPush(result, tempe[j].x, tempe);
//                CheckIndexInResultAndPush(result, tempe[j].y, tempe);
//            }
//
//            if (!CheckLoop(temps, tempe)) {
//                result.push_back({ s,e,v[s][e] });   
//                v[s][e] = 0;
//                count++;
//            }
//            else {
//                v[s][e] = 0;
//            }
//        }
//    }
//    return result;
//}
//
//int main()
//{
//    vector<vector<int>>v;
//    vector<set>result;
//    //Input(v);
//    v.push_back({ 0,4,0,0,0,0,0,8,0 });
//    v.push_back({ 0,0,8,0,0,0,0,11,0 });
//    v.push_back({ 0,0,0,7,0,4,0,0,2 });
//    v.push_back({ 0,0,0,0,9,14,0,0,0 });
//    v.push_back({ 0,0,0,0,0,10,0,0,0 });
//    v.push_back({ 0,0,0,0,0,0,2,0,0 });
//    v.push_back({ 0,0,0,0,0,0,0,1,6 });
//    v.push_back({ 0,0,0,0,0,0,0,0,7 });
//    v.push_back({ 0,0,0,0,0,0,0,0,0 });
//  /*  v.push_back({ 0,12,0,4,6,0,0,10,0,0,0,15 });
//    v.push_back({ 12,0,0,0,0,4,10,0,1,0,0,0 });
//    v.push_back({ 0,0,0,20,0,0,0,0,0,0,1,0 });
//    v.push_back({ 4,0,20,0,0,0,0,0,7,0,0,0 });
//    v.push_back({ 6,0,0,0,0,25,0,0,0,17,0,0 });
//    v.push_back({ 0,4,0,0,25,0,0,0,8,0,1,18 });
//    v.push_back({ 0,10,0,0,0,0,0,0,5,0,10,0 });
//    v.push_back({ 10,0,0,0,0,0,0,0,0,25,0,0 });
//    v.push_back({ 0,1,0,7,0,0,5,0,0,0,4,0 });
//    v.push_back({ 0,0,0,0,17,0,0,25,0,0,0,0 });
//    v.push_back({ 0,0,1,0,0,1,10,0,4,0,0,0 });
//    v.push_back({ 15,0,0,0,0,18,0,0,0,0,0,0 });*/
//   
//   /* v.push_back({ 0,1,3,4,0,0,0 });
//    v.push_back({ 1,0,0,8,0,8,0 });
//    v.push_back({ 3,0,0,10,6,0,11 });
//    v.push_back({ 4,8,10,0,0,7,5 });
//    v.push_back({ 0,0,6,0,0,0,6 });
//    v.push_back({ 0,8,0,7,0,0,9 });
//    v.push_back({ 0,0,11,5,6,9,0 });*/
//   
//   
//    result=CheckKaruskal(v);
//    int sum = 0;
//    for (int i = 0; i < result.size(); i++) {
//        result[i].display();
//        sum += result[i].weight;
//    }
//    cout << "Minimum Sum of Weights: " << sum << endl;
//    int s = 0, e = 0;
//    FindMinimum(v,s,e);
//   /* for (int i = 0; i < v.size(); i++) {
//        for (int j = 0; j < v.size(); j++) {
//            cout << v[i][j] << " ";
//        }
//        cout << endl;
//    }*/
//	system("pause");
//	return 0;
//}