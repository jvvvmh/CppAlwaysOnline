/*
Facotory Method design pattern

is a creatinal design pattern. 

Application only knows when a new Document should be created,
not what kind of Document to create!

Factory Method Participants:

Product: Defines the interface of objects the factory method creates.
ConcreteProduct: Implements the Product interface.
Creator: Declares to return an object of type Product.
ConcreteCreator: Overrides to return an instance of a ConcreteProduct.
*/ 

// parameterized factory methods
class Creator{
	Product FactoryMethod(ProductID id){
		if (id == MINE) return new MyProduct();
		if (id == YOURS) return new YourProduct(); 
	} 
}; 

// using templates to avoid subclass
template <class TheProduct> class Creator{
public:
	virtual Product* CreatProduct(){
		return new TheProduct;
	}
}

Class MyProduct: public Product{
  // ...
{
Creator<MyProduct> my Creator; 
