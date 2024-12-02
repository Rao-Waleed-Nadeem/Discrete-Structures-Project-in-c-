//#include<iostream>
//#include<string>
//#include<vector>
//using namespace std;
//
//class record {
//public:
//	vector<vector<int>>vertices;
//	record(int s) {
//		for (int i = 0; i < s; i++) {
//			vertices.push_back({0,0});
//		}
//	}
//	void SetVertex(int index,int count){
//		vertices[index][0] = count;
//	}
//	void Increment(int index) {
//		vertices[index][1]++;
//	}
//	vector<vector<int>>getInc() { return vertices; }
//
//	void display() {
//		for (int i = 0; i < vertices.size(); i++) {
//			cout << i << "  : " << vertices[i][0] << "   " << vertices[i][1] << endl;
//		}
//	}
//};
//
//void PushingVertices(vector<vector<int>>v,record &r) {
//	for (int i = 0; i < v.size(); i++) {
//		int count = 0;
//		for (int j = 0; j < v.size(); j++) {
//			if (v[i][j] != 0)count++;
//		}
//		r.SetVertex(i, count);
//	}
//}
//
//class set {
//public:
//	int x, y;
//	int weight;
//	set(int u,int v,int w):x(u),y(v),weight(w){}
//	void display() {
//		cout << "(" << x << "," << y << ")" << "   Weight: " << weight << endl;
//	}
//};
//
//void StartingCoordinate(vector <vector<int >> v, vector<set>&result) {
//	for (int i = 0; i < v.size(); i++) {
//		for (int j = 0; j < v.size(); j++) {
//			if (v[i][j] != 0) {
//				result.push_back({ i,j,v[i][j] });
//				return;
//			}
//		}
//	}
//}
//
//int FindMinimumVertexInRow(vector<vector<int>>&v, int s_index, vector<set>& result) {
//	int min = 0;
//	int index = -1;
//	for (int i = 0; i < v.size(); i++) {
//		bool alreadyInResult = false;
//		if (v[s_index][i] != 0) {
//			if (min == 0) {
//				for (int j=0; j < result.size(); j++) {
//					if (s_index == result[j].x && i == result[j].y||s_index==result[j].y&&i==result[j].x)
//						alreadyInResult = true;
//				}
//				if (!alreadyInResult) {
//					min = v[s_index][i];
//					index = i;
//				}
//			}
//			else {
//
//				for (int j = 0; j < result.size(); j++) {
//					if (s_index == result[j].x && i == result[j].y)
//						alreadyInResult = true;
//				}
//				if (!alreadyInResult) {
//					if (min > v[s_index][i]) {
//						min = v[s_index][i];
//						index = i;
//					}
//				}
//			}
//		}
//	}
//	return index;
//}
//
//void MinEdge(vector<set>temp, int& s, int& e) {
//	int min = temp[0].weight;
//	s = temp[0].x;
//	e = temp[0].y;
//	for (int i = 1; i < temp.size(); i++)
//	{
//		if (min > temp[i].weight) {
//			min = temp[i].weight;
//			s = temp[i].x;
//			e = temp[i].y;
//		}
//	}
//}
//
//void ConsecutiveVerticesMinimum(vector<vector<int>>&v, vector<vector<int>>&vertices,vector<set>&result,int &s,int &e) {
//	vector<set>temp;
//	for (int i = 0; i < vertices.size(); i++) {
//		if (vertices[i][1] != 0 && vertices[i][0]!=vertices[i][1]) {
//			int index = FindMinimumVertexInRow(v, i, result);
//			if (index != -1) {
//				temp.push_back({ i,index,v[i][index] });
//			}
//
//		}
//	}
//	 MinEdge(temp, s, e);
//}
//
//void MatchingPushInTemp(vector<set>& result, int& s, int& e, vector<set>& temps, vector<set>& tempe) {
//	for (int j = 0; j < result.size(); j++) {
//		if (s == result[j].x)temps.push_back(result[j]);
//		else if (s == result[j].y)temps.push_back(result[j]);
//		if (e == result[j].x)tempe.push_back(result[j]);
//		else if (e == result[j].y)tempe.push_back(result[j]);
//	}
//}
//
//bool PresentPair(vector<set>temp, set s) {
//	for (int i = 0; i < temp.size(); i++) {
//		if (temp[i].x == s.x && temp[i].y == s.y)return true;
//	}
//	return false;
//}
//
//void CheckIndexInResultAndPush(vector<set>& result, int index, vector<set>& temp) {
//	for (int i = 0; i < result.size(); i++) {
//		if (index == result[i].x || index == result[i].y) {
//			if (!PresentPair(temp, result[i])) {
//				temp.push_back(result[i]);
//			}
//		}
//	}
//}
//bool CheckLoop(vector<set>temps, vector<set>tempe) {
//	for (int i = 0; i < temps.size(); i++) {
//		for (int j = 0; j < tempe.size(); j++) {
//			if (temps[i].x == tempe[j].x && temps[i].y == tempe[j].y)return true;
//		}
//	}
//	return false;
//}
//
//void CheckForLoopAndPush(vector<vector<int>>&v,vector<set>&result,int &s,int&e,record &r) {
//	vector<set>temps;
//	vector<set>tempe;
//	MatchingPushInTemp(result, s, e, temps, tempe);
//
//	for (int j = 0; j < temps.size(); j++) {
//		CheckIndexInResultAndPush(result, temps[j].x, temps);
//		CheckIndexInResultAndPush(result, temps[j].y, temps);
//	}
//
//	for (int j = 0; j < tempe.size(); j++) {
//		CheckIndexInResultAndPush(result, tempe[j].x, tempe);
//		CheckIndexInResultAndPush(result, tempe[j].y, tempe);
//	}
//
//	if (!CheckLoop(temps, tempe)) {
//		result.push_back({ s,e,v[s][e] });
//		v[s][e] = 0;
//		v[e][s] = 0;
//	}
//	else {
//		v[s][e] = 0;
//		v[e][s] = 0;
//	}
//	r.Increment(s);
//	r.Increment(e);
//}
//
//vector<set> Prims(vector<vector<int>>v) {
//	vector<set>result;
//	record r(v.size());
//	PushingVertices(v,r);
//	//r.display();
//	for (int i = 0; i < v.size(); i++) {
//		int index = FindMinimumVertexInRow(v, i, result);
//		if (index != -1) {
//			result.push_back({ i,index,v[i][index] });
//			v[i][index] = 0;
//			v[index][i] = 0;
//			r.Increment(i);
//			r.Increment(index);
//			break;
//		}
//	}
//	while (  result.size() != v.size() - 1  ) {
//		int s = 0, e = 0;
//		ConsecutiveVerticesMinimum(v, r.vertices, result, s, e);
//		CheckForLoopAndPush(v, result, s, e, r);
//	}
//	return result;
//}
//
//int main()
//{
//	vector<vector<int>>v;
//	vector<set>result;
//
//	/*v.push_back({ 0,4,0,0,0,0,0,8,0 });
//	v.push_back({ 4,0,8,0,0,0,0,11,0 });
//	v.push_back({ 0,8,0,7,0,4,0,0,2 });
//	v.push_back({ 0,0,7,0,9,14,0,0,0 });
//	v.push_back({ 0,0,0,9,0,10,0,0,0 });
//	v.push_back({ 0,0,4,14,10,0,2,0,0 });
//	v.push_back({ 0,0,0,0,0,2,0,1,6 });
//	v.push_back({ 8,11,0,0,0,0,1,0,7 });
//	v.push_back({ 0,0,2,0,0,0,6,7,0 });*/
//
//	v.push_back({ 0,12,0,4,6,0,0,10,0,0,0,15 });
//	v.push_back({ 12,0,0,0,0,4,10,0,1,0,0,0 });
//	v.push_back({ 0,0,0,20,0,0,0,0,0,0,1,0 });
//	v.push_back({ 4,0,20,0,0,0,0,0,7,0,0,0 });
//	v.push_back({ 6,0,0,0,0,25,0,0,0,17,0,0 });
//	v.push_back({ 0,4,0,0,25,0,0,0,8,0,1,18 });
//	v.push_back({ 0,10,0,0,0,0,0,0,5,0,10,0 });
//	v.push_back({ 10,0,0,0,0,0,0,0,0,25,0,0 });
//	v.push_back({ 0,1,0,7,0,0,5,0,0,0,4,0 });
//	v.push_back({ 0,0,0,0,17,0,0,25,0,0,0,0 });
//	v.push_back({ 0,0,1,0,0,1,10,0,4,0,0,0 });
//	v.push_back({ 15,0,0,0,0,18,0,0,0,0,0,0 }); 
//
//	/*v.push_back({ 0,1,0,0,10,0,0 });
//	v.push_back({ 1,0,7,0,0,0,8 });
//	v.push_back({ 0,7,0,4,0,0,9 });
//	v.push_back({ 0,0,4,0,3,5,0 });
//	v.push_back({ 10,0,0,3,0,2,0 });
//	v.push_back({ 0,0,0,5,2,0,6 });
//	v.push_back({ 0,8,9,0,0,6,0 });*/
//	//v.push_back({ 0,0,0,0,17,0,5,0,0,0,26 });
//	//v.push_back({ 0,0,31,0,0,19,0,13,7,0,0 });
//	//v.push_back({ 0,31,0,8,47,0,0,0,0,0,0 });
//	//v.push_back({ 0,0,8,0,0,4,3,0,0,0,1 });
//	//v.push_back({ 17,0,47,0,0,0,0,0,24,10,6 });
//	//v.push_back({ 0,19,0,4,0,0,0,0,0,0,0 });
//	//v.push_back({ 5,0,0,3,0,0,0,0,0,0,0 });
//	//v.push_back({ 0,13,0,0,0,0,0,0,0,9,0 });
//	//v.push_back({ 0,7,0,0,24,0,0,0,0,2,0 });
//	//v.push_back({ 0,0,0,0,10,0,0,9,2,0,0 });
//	//v.push_back({ 26,0,0,1,6,0,0,0,0,0,0 });
//	
//	
//
//	result = Prims(v);
//	int sum = 0;
//	for (int i = 0; i < result.size(); i++) {
//		result[i].display();
//		sum += result[i].weight;
//	}
//	cout << "Total weight/cost: "<<sum << endl;
//
//	system("pause");
//	return 0;
//}