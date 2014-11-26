#ifndef GRAPH_H
#define GRAPH_H
unsigned int** getlength(unsigned int size)
{
	unsigned int ** result = new unsigned int *[size];
	for (int i = 0; i < size; ++i)
	{
		result[i] = new unsigned int[size];
	}
	return result;
}
//input the two-dimension the second dimension size and the array
void distroylength(unsigned int** len,unsigned int n)
{
	for (int i = 0; i <n; ++i)
	{
		delete []len[i];
	}
	delete[] len;
}
template<typename T>
T* getOneDimArray(unsigned int _size)
{
	return new T[_size];
}
#define NMAX 100
#define LARGEINT 9999
#include <exception>
#include <iostream>
class Graph
{
public:
	Graph(std::istream& in)
	{
		try{
			in>>gpn;
			init();
			initLength(in);
		}catch(std::exception e)
		{
			e.what();
		}
		
	}

	Graph(unsigned int _size):gpn(_size)
	{
		try{
			init();
		}catch(std::exception e)
		{
			e.what();
		}
		
	}
	Graph():gpn(NMAX)
	{
		try
		{
			init();
		}catch(std::exception e)
		{
		 	e.what();
		}
		
	}
	~Graph()
	{
		delete[] s;
		delete[] path;
		delete[] dist;
		distroylength(length,gpn);
	}
	//calculate the shortestpath
	void shortestPath(const int v)
	{
		startGraphPoint = (unsigned int)v;
		for (int i = 0; i < this->gpn; ++i)
		{
			s[i] = false; 
			dist[i] = length[v][i];
			if(i!=v && dist[i]<LARGEINT)
				path[i] = v;
			else
				path[i] =-1;
		}
		s[v] = true;
		dist[v] = 0;
		for (int i = 0; i < this->gpn-2; ++i)
		{
			int u = choose();//select u, 
			s[u] = true;
			for(int w=0;w< this->gpn ;w++)
			{
				if(!s[w])
				{
					if(dist[u]+length[u][w]<dist[w])
					{
						dist[w] = dist[u]+length[u][w];
						path[w] = u;
					}
				}//end if
			}//end for(w=0..)
		}//end for(i=1..)

	}
	//dist[u]= min{dist[x]} (x not in S ),return u
	int choose()const
	{
	 	int min=-1;
	 	int mindist=LARGEINT;
	 	for(int i=0;i<this->gpn;i++)
	 	{
	 		if(!s[i])
	 		{
	 			if(dist[i]<mindist)
	 			{		
	 				mindist=dist[i];
	 				min = i;
	 			}
	 		}
	 	}
	 	return min;
	}
	void printShortestPath(const int start,const int end)
	{
		if(start!=0 && start==this->startGraphPoint)
		{
			getPath(end);
		}else{
			shortestPath(start);
			getPath(end);
		}
	}
	void display()const
	{
		/*for (int i = 0; i < this->gpn; ++i)
		{
			for (int j = 0; j < this->gpn; ++j)
			{
				std::cout<<length[i][j]<<'\t';
			}
			std::cout<<'\n';
		}*/
		std::cout<<"\n dist[] is:";
		for (int i = 0; i < this->gpn; ++i)
		{
			std::cout<<dist[i]<<'\t';
		}
		std::cout<<"\n Path is:";
		for (int i = 0; i < this->gpn; ++i)
		{
			std::cout<<path[i]<<'\t';
		}
		std::cout<<"\n";
	}
	unsigned int getGraphNodeNumber()const
	{
		return this->gpn;
	}
private:
	unsigned int gpn;//graph point number
	unsigned int startGraphPoint;
	unsigned int** length; //save the length of every two points distance
	unsigned int* dist;  //save the start point to others distance
	int* path; //save the last point in the shortestPath of 1 to others
	bool* s; //save the sign of the point in the S or not
	void init()
	{
		length = getlength(this->gpn);
		dist = getOneDimArray<unsigned int>(this->gpn);
		path = getOneDimArray<int>(this->gpn);
		s = getOneDimArray<bool>(this->gpn);
	}
	std::istream& initLength(std::istream& in)
	{
		for(int i=0;i<gpn;i++)
			for(int j=0;j<gpn;j++)
				in>>length[i][j];
		return in;
	}
	void getPath(const int end)const
	{
		if(path[end]==-1)
				std::cout<<this->startGraphPoint<<"-/->"<<end<<"\n";
		else 
		{
			int current=end;
			int i=0;
			unsigned int *temp = new unsigned int[this->gpn];
			temp[i++]=current;
			while(path[current]!=-1)
			{
				current = path[current];
				temp[i++]=current;
			}
			std::cout<<this->startGraphPoint<<"——>"<<end<<":";
			while(--i>=0)std::cout<<temp[i]<<"\t";
			std::cout<<"\n";
			delete[] temp;
		}
	}
};
#endif
