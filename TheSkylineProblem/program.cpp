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
	int rightEnd = 0;
	vector<pair<int, int>> rightTmp;
	for_each(buildings.begin(), buildings.end(), [&](vector<int> building){
		int rightPointHeight = 0;
		for ( ;it_RightTmp != rightTmp.end(); )
		{
			// Check right points array
			// If it locates at left side of the current building,
			// push it to result vector
			if (building[0] > it_RightTmp[0].first)
			{
				rst.push_back(it_RightTmp[0]);
				it_RightTmp = rightTmp.erase(it_RightTmp);
				continue;
			}

			// If the left point higher than former left point
			if (rst.rbegin()[0].second < building[2]){
				// Save current right height
				rightPointHeight = rst.rbegin()[0].second;
				// Push back the left point to result vector
				rst.push_back(pair<int, int>(building[0], building[2]));
			}

			// If current right point not coverd by current building,
			// insert new right point with current height
			if (building[1] < it_RightTmp[0].first)
			{
				rst.insert(pair<int, int>(building[2], rightPointHeight));
				break;
			}

			// Check if current right point is coverd by current building
			if (building[2] > it_RightTmp[0].second)
			{
				rightPointHeight = it_RightTmp[0].second;
				it_RightTmp[0].second = building[2];
			}
			it_RightTmp++;
			continue;

		}
		// For begin and end points
		if (building[0] > rightEnd){
			rst.push_back(pair<int, int>(rightEnd, 0));
			rightEnd = building[0][1];
			// New building series
			rst.push_back(pair<int, int>(building[0], building[2]);
		}
	});
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
