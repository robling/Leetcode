#include "../include/prevector.h"
using std::pair;
using std::for_each;

//Not Pased because it requires to much menory
namespace PreOpenedArray{
const int Max_NUM = 10000;
vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings){
	if (buildings.size() == 0 || buildings.begin()[0].size() == 0)
		return vector<pair<int, int>>();
	int contour[Max_NUM] = {0};
	int rightEnd = 0;
	for_each(buildings.begin(), buildings.end(), [&](vector<int> building){
		for (int i = building[0]; i != building[1] + 1;i++){
			if (contour[i] < building[2])
				contour[i] = building[2];
		}
		if (building[1] > rightEnd)
			rightEnd = building[1];
	});
	vector<pair<int, int>> rst;
	int foward = 0;
	for(int i = buildings.begin()[0][0]; i < rightEnd; i ++)
	{
		foward = contour[i + 1];
		if (contour[i] != foward){
			rst.push_back(pair<int, int>(i, (foward < contour[i]) ? foward : contour[i]));
		}
	}
	rst.push_back(pair<int, int>(rightEnd, 0));
	return rst;
}
}

vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings){
	if (buildings.size() == 0 || buildings[0][0].size() == 0)
		return vector<pair<int, int>>();
	vector<pair<int, int>> rst;

}

void Mymain()
{
	TIC
	vector<vector<int>> input = {
		//{2, 9, 10}, {3, 7, 15}, {5, 12, 12}, {15, 20, 10}, {19, 24, 8}
		{}
	};
	auto rst = getSkyline(input);
	for (auto p : rst){
		cout << "(" << p.first << ", " << p.second << ")";
		cout << ",";
	}
	cout << endl;
	TOC
}
