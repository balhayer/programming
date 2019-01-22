//Write a money register at a specific grocery store which calculates
//the gross amount bill of all individual groceries.

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


struct item
{
	string name;
	int code;
	float price;
};
class FinalBill
{
private:
	vector <item> v;
public:
	FinalBill()
	{
		v.clear();
	}
void readFile(string filename)
	{
		std::ifstream file;
		string line, word;
		stringstream nod;
		int ind, prev;
		item e;

		file.open(filename);
		while (getline(file, line)) 
	{
			prev = -1;
			ind = line.find(" ", prev + 1);
			word = line.substr(prev + 1, ind - prev - 1); 

														 
			nod << word;
			nod >> e.code;
		 	nod.clear();

			prev = ind;
			ind = line.find(" ", prev + 1);
			word = line.substr(prev + 1, ind - prev - 1); 

														  
			nod << word;
			nod >> e.price;
			nod.clear();

			prev = ind;
			word = line.substr(prev + 1);
			e.name = word;

			v.push_back(e); 
		}
}
float getTotal(int itemCodes[], int nItems)
{
		float cost = 0;
		for (int i = 0;i <nItems;i++)
		{
			for (int m = 0;m<v.size();m++)
			{
				if (itemCodes[i] == v[m].code)
				{
					cost += v[m].price;
					break;
				}
			}
		}
		return cost;
	}

private:
    vector <FinalItems> GroceryItem;
};




int main() {
	 
	myFinalBill.readFile("pricelist.txt");
	int codes[] = { 34302, 10078, 34302 };
	cout << "TOTAL = " << myFinalBill.getTotal(codes, 3) << "(Total 3.29)" << endl;
	return 0;
}
