#include <iostream>
#include <list>
#include <algorithm>
#include <string>

using namespace std;


template<class V, class A>
class Edge;

template<class V,class A>
class Vertex
{
public:
	V                   m_Dato;
	list<Edge<V,A> >    m_list_Edge;
	
	Vertex(V vertice)
	{
		m_Dato = vertice;
	}
	
};

template<class V,class A>
class Edge
{
public:
	A                   m_Dato;
	Vertex<V,A>  *      m_pVertex;
	
	Edge(A a, Vertex<V,A>  *q = 0)
	{
		m_Dato = a;
		m_pVertex=q;
	}
};



template<class V,class A>
class Graph
{
private:
	list< Vertex <V,A> >   m_Graph;
public:
	Graph(){};
	
	void Insert(V Vertice)
	{
		m_Graph.push_back(Vertex<V,A>(Vertice));
	};
	void Insert_Edge(V v1, V v2, A a)
	{
		Vertex<V,A> * p = find_Vertex(v1);
		Vertex<V,A> * q = find_Vertex(v2);
		if(p && q)
		{ 
			// ¿Qué ocurre si la arista y existe?
			Edge<V,A>  r(a,q);
			p->m_list_Edge.push_back(r); //agrego aristas a una m_list_Edge del Vertice v1
		}
		
		
	};
	Vertex<V,A> * find_Vertex(V v)
	{
		typedef typename   list< Vertex <V,A>>::iterator Iterator_Vertex; 
		Iterator_Vertex  p = std::find(m_Graph.begin(), m_Graph.end(), Vertex<V,A>(v));
		return *(*p);
	} 
	
	bool find_edge(V v, A a)
    {
        Vertex<V, A> *p = find_Vertex(v);
        // write your code here         
        typedef typename list<Edge<V, A>>::iterator Iterator_Edge;
        Iterator_Edge edge=std::find(p->m_list_Edge.begin(),p->m_list_Edge.end(),Edge<V,A>(a));
        if(edge){
            return true;
        }
        return false;
    }
	void Print()
	{
		typedef typename   list< Vertex <V,A>>::iterator Iterator_Vertex; 
		Iterator_Vertex it = m_Graph.begin();
		for(; it != m_Graph.end();it++)
		{
			cout<<it->m_Dato<<endl;
			// write your code here
		}
		
	};
	
	
	
};

int main()
{
	Graph<string, int>  G;
	G.Insert("Arequipa");
	G.Insert("Lima");
	G.Insert("Cusco");
	G.Insert("Puno");
	G.Insert("Tacna");
	G.Insert("Ica");
	
	G.Insert_Edge("Arequipa","Cusco",100);
	G.Insert_Edge("Tacna","Cusco",160);
	G.Insert_Edge("Arequipa","Lima",1500);
	G.Insert_Edge("Puno","Ica",1500);
	G.Insert_Edge("Cusco","Puno",1070);
	G.Insert_Edge("Arequipa","Puno",400);
	G.Insert_Edge("Ica","Tacna",600);
	
	G.Print();
	
	return 0;
	
}
