/**
 * @ Brief: Builder Design Pattern,
 *          这种设计模式比较适合产品已经成型，流水线式的进行产品生产，每个产品的结构不同
            Builder也不同
 * @ author: charles<cwlseu@qq.com>
 * @ Create Date: 2014-12-3
 **/
 #include <iostream>
 /**
  * class product is the Builder would build
  **/
class Product
{
public:
	Product(){}
	Product(int data1,int data2,int data3):part_1(data1),part_2(data2),part_3(data3)
	{

	}
public:
	int part_1,part_2,part_3;
public:
	void setPart_1(int data)
	{
		this->part_1= data;
		std::cout<<"set Part 1\n";
	}
	void setPart_2(int data)
	{
		this->part_2= data;
		std::cout<<"set Part 2\n";
	}
	void setPart_3(int data)
	{
		this->part_3= data;
		std::cout<<"set Part 3\n";
	}
	bool operator==(const Product& p)
	{
		return !((this->part_1!=p.part_1)||(this->part_2!=p.part_2)||(this->part_3!=p.part_3));
	}
};
//interface of the builder, the interface should design with the
//Product, if the product have different structure ,the interface will
//redesigned
class IBuilder
{
public:
	Product* product;
public:

	virtual void buildProductPart_1()=0;
	virtual void buildProductPart_2()=0;
	virtual void buildProductPart_3()=0;
	Product& buildProduct()
	{
		return *product;
	} 
};
//
class CBuilder
	:public IBuilder
{
public:
	CBuilder()
	{
		IBuilder::product = new Product();
	}
	void buildProductPart_1()
	{
		product->setPart_1(1);
	}
	void buildProductPart_2()
	{
		product->setPart_2(2);
	}
	void buildProductPart_3()
	{
		product->setPart_3(3);
	}

	Product& buildProduct()
	{
		mainBuilder();
		return *product;
	} 
private:
	//builder method to invoke other part,the sequence of building part 
	//should consistent with reality life.
	void mainBuilder(void)
	{
		this->buildProductPart_1();
		this->buildProductPart_2();
		this->buildProductPart_3();
	}
};
