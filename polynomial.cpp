#include<iostream>
using namespace std;
class Polynomial
{
	int array[200];
	int degree;
	 // Variables to store information about polynomial
	public:
	 	 	Polynomial()                //default constructor
	 	    {
	 		degree=1;
		    }
		    Polynomial(int deg)        //parameterise constructor
		    {
			   degree=deg;            // Behavior of constructor with arguments
			   degree++;	
		    }
		~Polynomial()                  //destructor
        {
            degree=0; // Behavior of destructor
        }
         
        Polynomial operator +(Polynomial d)            //  Overload copy constructor, +, - and = operators
		{
			Polynomial p;
			p.degree=this->degree>=d.degree? this->degree:d.degree;
			for(int i=0;i<p.degree;i++)
			{
				if(i>=this->degree)
				  this->array[i]=0;
				if(i>=d.degree)
				  d.array[i]=0;
				  p.array[i]=d.array[i]+this->array[i];  
			}
			return p;
		}
		Polynomial operator -(Polynomial d)
		{
			Polynomial p;
			p.degree=this->degree>=d.degree? this->degree:d.degree;
			for(int i=0;i<p.degree;i++)
			{
				if(i>=this->degree)
				  this-> array[i]=0;
				if (i>=d.degree)
				  d.array[i]=0;
				  p.array[i]=this->array[i]-d.array[i];  
			} 
		    return p;	
	    }
	    Polynomial operator =(Polynomial poly)
		{
			Polynomial p;
			this->degree=poly.degree;
			for(int i=0;i<this->degree;i++)
			  this->array[i]=poly.array[i];
	    }
	    void storePolynomial()                   //   enter and store polynomial	
        {
                
            cout<<"\n enter the cofficient in ascending order of power"<<endl;
			for(int i=0;i<degree;i++)
			cin>>array[i];
 	    }
 	    void display()                           //  print the polynomial in readable format
        {
            
            cout<<endl;
            for(int i=0;i<degree;i++)
            {
            	cout<<array[i]<<"X^"<<i;
            	if(i<degree-1)
            	  cout<<" + ";
			}
	    }
};
int main()
{
	int degFirst, degSecond;
	cout<<"enter the degrees";
    cin>>degFirst>>degSecond;
    // Ask user to input the values of degFirst and degSecond 
    Polynomial firstPolynomial(degFirst);
    Polynomial secondPolynomial(degSecond);
    Polynomial thirdPolynomial;
  
    firstPolynomial.storePolynomial();
    secondPolynomial.storePolynomial();
   
    thirdPolynomial=firstPolynomial+secondPolynomial;
    Polynomial fourthPolynomial=firstPolynomial-secondPolynomial;
  
    cout<<"\n the first polynomial is :";
    firstPolynomial.display();
    cout<<endl;
    cout<<"\n the second polynomial is : ";
    secondPolynomial.display();
    cout<<endl;
    cout<<"\n the third polynomial obtained after adding is :";
    thirdPolynomial.display();
    cout<<endl;
    cout<<"\n the first polynomial obtained after subtracting is :";
    fourthPolynomial.display();
    return 0;
}
