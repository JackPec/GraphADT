#include <iostream>
#include <list>
#include <vector>
#include <algorithm>

template <typename K, typename V>
class Entry   // a (key, value) pair
{
public: // public types
    typedef K Key; // key type
    typedef V Value; // value type
public: // public functions
    Entry(const K& k = K(), const V& v = V()) // constructor
        : _key(k), _value(v) { }
    const K& key() const
    {
        return _key;    // get key (read only)
    }
    const V& value() const
    {
        return _value;    // get value (read only)
    }
    void setKey(const K& k)
    {
        _key = k;    // set key
    }
    void setValue(const V& v)
    {
        _value = v;    // set value
    }

private: // private data
    K _key; // key
    V _value; // value
};


template <typename E>
class Edge;

template <typename E>
class Vertex
{
public:
    E Elem;
    std::list<Edge<E>> edgesIncidentTothis;


    Vertex(): Elem(), edgesIncidentTothis()
    {



    }

    E& getElt()
    {
        return Elem;

    }

    void setValue(const E& e)
    {
        Elem = e;    // set value
    }

    std::list<Edge<E>> incidentEdges()
    {
        return edgesIncidentTothis;
    }

    bool isAdjacentTo(Vertex& v)
    {
        bool returnVal = false;

        // std::list<Edge<E>> total = edgesIncidentTothis.merge(v.edgesIncidentTothis);

        typedef typename std::list<Edge<E>>::iterator IteratorE;
        typedef typename std::list<Vertex<E>>::iterator IteratorV;

        for(IteratorE k = edgesIncidentTothis.begin();
            k != edgesIncidentTothis.end(); ++k)
        {

            for(IteratorV p = k->verticesIncidentTothis.begin();
                p != k->verticesIncidentTothis.end(); ++p)
            {
                if(p->getElt().key() == v.getElt().key())
                {
                    returnVal = true;
                }

            }



        }



        /*
                   if(p->verticesIncidentTothis.front().getElt().key() == Elem.key()
                       || p->verticesIncidentTothis.back().getElt().key() == Elem.key())
                   {
                           returnVal = true;

                   }
                   */


        /*

        for(IteratorE k = edgesIncidentTothis.begin(); k != edgesIncidentTothis.end(); ++k)
        {
            for(IteratorE p = v.edgesIncidentTothis.begin(); p != v.edgesIncidentTothis.end(); ++p)
            {
                if(k->getElt().key() == p->getElt().key() )
                {
                    returnVal = true;

                }


            }


        }

        */

        return returnVal;

    }









};

template <typename E>
class Edge
{
public:
    E Elem;
    std::list<Vertex<E>> verticesIncidentTothis;

    Edge(): Elem(), verticesIncidentTothis()
    {

    }

    E& getElt()
    {
        return Elem;

    }

    void setValue(const E& e)
    {
        Elem = e;    // set value
    }

    std::list<Vertex<E>> endVertices()
    {
        return verticesIncidentTothis;

    }


    bool isAdjacentTo(Edge<E>& f)
    {
        bool returnVal = false;

        typedef typename std::list<Edge<E>>::iterator IteratorE;
        typedef typename std::list<Vertex<E>>::iterator IteratorV;

        for(IteratorV k = verticesIncidentTothis.begin();
            k != verticesIncidentTothis.end(); ++k)
        {

            for(IteratorE p = k->edgesIncidentTothis.begin();
                p != k->edgesIncidentTothis.end(); ++p)
            {
                if(p->getElt().key() == f.getElt().key())
                {
                    returnVal = true;
                }

            }



        }


        return returnVal;



    }


    bool isIncidentOn(Vertex<E>& v)
    {
        bool value = false;

        typedef typename std::list<Vertex<E>>::iterator Iterator;

        for(Iterator e = verticesIncidentTothis.begin();
            e != verticesIncidentTothis.end(); ++e)
        {
            if(e == v)
            {
                value = true;

            }

        }

        return value;



    }





};

template <typename E>
class Graph
{
public:

    std::list<Edge<E>> EdgeList;
    std::list<Vertex<E>> VertexList;

    Graph() : EdgeList(), VertexList()
    {

    }

    std::list<Edge<E>> edges()
    {
        return EdgeList;
    }

    std::list<Vertex<E>> vertices()
    {
        return VertexList;
    }

    Vertex<E> insertVertex(E x)
    {
        Vertex<E> a;
        a.setValue(x);
        VertexList.push_back(a);

        return a;
    }

    Vertex<E> insertVertex(Vertex<E> x)
    {
        VertexList.push_back(x);

        return x;
    }

    /*
    Edge<E> insertEdge(Vertex<E>& v,Vertex<E>& w, E& e)
    {
        Edge<E> newEdge;
        newEdge.setValue(e);

        newEdge.verticesIncidentTothis.push_back(v);
        newEdge.verticesIncidentTothis.push_back(w);

        v.edgesIncidentTothis(newEdge);
        w.edgesIncidentTothis(newEdge);

        return newEdge;

        //v.edgesIncidentTothis.push_back();
      //  w.edgesIncidentTothis.push_back(v);


    }
    */

    Edge<E> insertEdgebyKey(const E& v,const E& w,const E& e)
    {

        typedef typename std::list<Vertex<E>>::iterator Iterator;


        //if()

        //Iterator e = VertexList.begin() e.getElt().key() != E.key(); ++e)

        // Iterator v1 = VertexList.begin();
        // Iterator v2 = VertexList.begin();
        // Vertex<E> temp = *p;

        // v1.find(v);
        // v2.find(w);

        //std::find(v1,)

        //Iterator v1 = std::find(VertexList.begin(),VertexList.end(),v);

        Iterator v1 = VertexList.begin();
        Iterator v2 = VertexList.begin();

        while((*v1).getElt().key() != v.key() && v1 != VertexList.end())
        {
            ++v1;
        }

        while((*v2).getElt().key() != w.key() && v2 != VertexList.end())
        {
            ++v2;
        }







        Edge<E> newEdge;
        newEdge.setValue(e);

        newEdge.verticesIncidentTothis.push_back(*v1);
        newEdge.verticesIncidentTothis.push_back(*v2);

        (v1->edgesIncidentTothis).push_back(newEdge);
        (v2->edgesIncidentTothis).push_back(newEdge);

        //v1.edgesIncidentTothis(newEdge);
        //v2->edgesIncidentTothis(newEdge);

        EdgeList.push_back(newEdge);

        return newEdge;

        //v.edgesIncidentTothis.push_back();
        //  w.edgesIncidentTothis.push_back(v);


    }

    void eraseVertex(Vertex<E>& v)
    {
        typedef typename std::list<Vertex<E>>::iterator Iterator;
        Iterator v1 = VertexList.begin();

        while((*v1).getElt().key() != v.getElt().key()
                                    && v1 != VertexList.end())
        {
            ++v1;
        }

        if(v1->getElt().key() == v.getElt().key())
            VertexList.erase(v1);


    }

    void eraseEdge(Edge<E>& e)
    {
        //EdgeList.erase(v);

        typedef typename std::list<Edge<E>>::iterator Iterator;
        Iterator e1 = EdgeList.begin();

        while((*e1).getElt().key() != e.getElt().key()
                                && e1 != EdgeList.end())
        {
            ++e1;
        }

        if(e1->getElt().key() == e.getElt().key())
            EdgeList.erase(e1);

    }

    void eraseEdge(const E& e)
    {
        //EdgeList.erase(v);

        typedef typename std::list<Edge<E>>::iterator Iterator;
        Iterator e1 = EdgeList.begin();

        while((*e1).getElt().key() != e.key() && e1 != EdgeList.end())
        {
            ++e1;
        }

        if(e1->getElt().key() == e.key())
            EdgeList.erase(e1);

    }



    friend class Edge<E>;
    friend class Vertex<E>;

};


int main()
{




    /*




        Graph looks like this


                    a(0,0)
                   / \
           e(0,4) /   \  e(1,4)
                 /_____\
                b(1,1)  c(2,2)
                   e(2,4)







    */

    Graph<Entry<int,int>> graph;
    std::cout<<"\n\nGraph 1: \n\n";

    std::cout<<"\nThe graph should look like this:\n\n";
    std::cout<<"            V(0,0)              \n";
    std::cout<<"           / \\             \n";
    std::cout<<"   E(0,4) /   \\ E(1,4)              \n";
    std::cout<<"         /_____\\              \n";
    std::cout<<"        V(1,1)  V(2,2)              \n";
    std::cout<<"           E(2,4)              \n";


    Vertex<Entry<int,int>> a;
    a.getElt().setKey(0);
    a.getElt().setValue(0);

    Vertex<Entry<int,int>> b;
    b.getElt().setKey(1);
    b.getElt().setValue(1);

    Vertex<Entry<int,int>> c;
    c.getElt().setKey(2);
    c.getElt().setValue(2);

    /*
    graph.insertVertex(Entry<int,int>(0,0));
    graph.insertVertex(Entry<int,int>(1,1));
    graph.insertVertex(Entry<int,int>(2,2));
    */

    graph.insertVertex(a);
    graph.insertVertex(b);
    graph.insertVertex(c);

    graph.insertEdgebyKey(a.getElt().key(),b.getElt().key(),
                          Entry<int,int>(0,4));
    graph.insertEdgebyKey(a.getElt().key(),c.getElt().key(),
                          Entry<int,int>(1,4));
    graph.insertEdgebyKey(b.getElt().key(),c.getElt().key(),
                          Entry<int,int>(2,4));


    // std::list<Edge<Entry<int,int>>> edgeOutput = graph.edges();
    std::list<Vertex<Entry<int,int>>> vertexOutput = graph.vertices();

    typedef typename std::list<Vertex<Entry<int,int>>>::iterator IteratorV;
    typedef typename std::list<Edge<Entry<int,int>>>::iterator IteratorE;

    for(IteratorV e = vertexOutput.begin(); e != vertexOutput.end(); ++e)
    {
        std::cout << "\nVertex: ";
        std::cout << "V(" << e->getElt().key() <<", "
        << e->getElt().value() << ")\n";
        // std::cout << "\n-----------------\n";
        std::cout << "This vertex is connected to edges: \n";


        // IteratorE j = e->edgesIncidentTothis.begin();

        for(IteratorE p = e->edgesIncidentTothis.begin();
            p != e->edgesIncidentTothis.end(); ++p)
        {
            std::cout << "E(" << p->getElt().key() <<", "
            << p->getElt().value() << ")\n";


        }

        std::cout << "This vertex is incident to vertices: \n";


        for(IteratorE p = e->edgesIncidentTothis.begin();
            p != e->edgesIncidentTothis.end(); ++p)
        {
            for(IteratorV k = p->verticesIncidentTothis.begin();
                k != p->verticesIncidentTothis.end(); ++k)
            {

                if(e->isAdjacentTo(*k)
                   && e->getElt().key() != k->getElt().key())
                {
                    std::cout << "V(" << k->getElt().key() <<", "
                    << k->getElt().value() << ")\n";

                }

            }

        }






    }

    // graph.eraseVertex(a);
    //  graph.eraseEdge(Entry<int,int>(0,4));



    ///////////////////////////////////////////////////////////Graph 2

    Graph<Entry<int,int>> graph2;


    /*


    V(0,0)------V(1,1)-----V(2,2)

         E(0,4)        E(1,4)



    */

    std::cout<<"\n\nGraph 2: \n\n";
    std::cout<<"\nThe graph should look like this:\n\n";
    std::cout<<"\nV(0,0)------V(1,1)-----V(2,2)\n";
    std::cout<<"     E(0,4)        E(1,4)            \n\n";


    graph2.insertVertex(a);
    graph2.insertVertex(b);
    graph2.insertVertex(c);

    graph2.insertEdgebyKey(a.getElt().key(),b.getElt().key(),
                           Entry<int,int>(0,4));
    // graph.insertEdgebyKey(a.getElt().key(),c.getElt().key(),Entry<int,int>(1,4));
    graph2.insertEdgebyKey(b.getElt().key(),c.getElt().key(),
                           Entry<int,int>(1,4));

    vertexOutput = graph2.vertices();


    for(IteratorV e = vertexOutput.begin(); e != vertexOutput.end(); ++e)
    {
        std::cout << "\nVertex: ";
        std::cout << "V(" << e->getElt().key() <<", "
        << e->getElt().value() << ")\n";
        // std::cout << "\n-----------------\n";
        std::cout << "This vertex is connected to edges: \n";


        // IteratorE j = e->edgesIncidentTothis.begin();

        for(IteratorE p = e->edgesIncidentTothis.begin();
            p != e->edgesIncidentTothis.end(); ++p)
        {
            std::cout << "E(" << p->getElt().key() <<", "
            << p->getElt().value() << ")\n";


        }

        std::cout << "This vertex is incident to vertices: \n";


        for(IteratorE p = e->edgesIncidentTothis.begin();
        p != e->edgesIncidentTothis.end(); ++p)
        {
            for(IteratorV k = p->verticesIncidentTothis.begin();
                k != p->verticesIncidentTothis.end(); ++k)
            {

                if(e->isAdjacentTo(*k)
                   && e->getElt().key() != k->getElt().key())
                {
                    std::cout << "V(" << k->getElt().key() <<", "
                    << k->getElt().value() << ")\n";

                }

            }

        }

    }







    return 0;
}
