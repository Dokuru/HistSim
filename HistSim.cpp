//============================================================================
// Name        : HistSim.cpp
// Author      : Nico Herbig
// Version     : 0.1
// Copyright   : (C) 2015 Nico Herbig
// Description : Main file for histone simulation
//============================================================================

#include <iostream>
#include <map>
#include <string>
#include <boost/variant/variant.hpp>
#include <boost/variant/get.hpp>
#include "rapidxml/rapidxml.hpp"
#include "rapidxml/rapidxml_utils.hpp"
#include "rapidxml/rapidxml_print.hpp"
//#include "helper.hpp"
#include "chromatin.hpp"

//using namespace std;

int main()
{

	int verbose = 1;

	//parsing config file

	rapidxml::file<> xmlFile("config.cfg");
	rapidxml::xml_document<> doc;

	doc.parse<0>(xmlFile.data());


	//table to store simulation parameters (keyis string, values either string or int
	std::map< std::string, boost::variant<std::string, int> > simparams;



	rapidxml::xml_node<> *node = doc.first_node("nNucleosomes");

	rapidxml::xml_attribute<> *attr;

	std::cout << "\nGetting number of nucleosomes: \n \n";

	if(node)
	{
		attr = node->first_attribute("value");

		simparams["nNucleosomes"] = attr->value();

		if(verbose)
		{
			std::cout << " Number of nucleosomes: " << simparams["nNucleosomes"] << "\n ";
		}


	}
	else
	{
		std::cout << "Number of nucleosomes not defined! \n";
		exit(1);
	}

	node = doc.first_node("histoneModifications");

	//TODO: support for multiple modification instances

	std::cout << "\nGetting modifications: \n \n ";

	if(node)
	{
		for (rapidxml::xml_node<> *child = node->first_node(); child; child = child->next_sibling())
		{
			attr = child->first_attribute("name");

			simparams["modname"] = attr->value();

			attr = child->first_attribute("value");

			simparams["modvalue"] = attr->value();

			if(verbose)
			{
				std::cout << "Modification name: " << simparams["modname"] << "\n ";
				std::cout << "Modification value: " << simparams["modvalue"] << "\n ";
			}
		}
	}
	else
	{
		std::cout << "Histone modifications not defined! \n";
		exit(1);
	}


	node = doc.first_node("cyclicChromosomes");

	std::cout << "\nGetting cyclic info: \n \n ";

	if(node)
	{
		attr = node->first_attribute("value");

		simparams["cyclic"] = attr->value();

		if(verbose)
		{
			std::cout << "Cyclic chromosomes: " << simparams["cyclic"] << "\n ";
		}


	}
	else
	{
			std::cout << "Cyclic chromosomes not defined! \n";
			exit(1);
	}


	node = doc.first_node("initialState");


	std::cout << "\nGetting initial state: \n \n ";


	simparams["initstate"] = "(H3[27.4])(H4[5.2])|(H3[27.4])(H4[5.2])|(H3[27.4])(H4[5.2])|(H3[27.4])(H4[5.2])|(H3[27.4])(H4[5.2])|(H3[27.4])(H4[5.2])|(H3[27.4])(H4[5.2])|(H3[27.4])(H4[5.2])|(H3[27.4])(H4[5.2])|(H3[27.4])(H4[5.2])";

	//TODO: support for multiple modification instances

	/*if(node)
	{
		//std::cout << "TEST \n ";
		//for (rapidxml::xml_node<> *child = node->first_node(); child; child = child->next_sibling())
		//{
			//attr = child->first_attribute("type");

			attr = node->first_attribute("type");


			std::string tmpstr = attr->value();



			if(tmpstr.compare("custom") == 0)
			{
				simparams["initstate"] = node->first_attribute("value")->value();



			}
			/*else if(!tmpstr.compare("twoParts"))
			{

				std::string& tmpstr = boost::get<std::string>(simparams["nNucleosomes"]);
				int boundary = atoi(tmpstr.c_str())/2;

				//std::cout << child->first_attribute("type")->value();

				//std::cout << boundary;

				simparams["initstate"] = "inProgress";

			}

			*/


			if(verbose)
			{
				std::cout << "Initial state: " << simparams["initstate"] << "\n ";

			}

		//}
	/*}
	else
	//{
		std::cout << "Initial state not defined! \n";
		exit(1);
	}
	*/


	std::cout << " \nSetting up objects... \n \n";





	
	//initializing nucleosome list / chromatin
	
	std::vector<int> originpos;
	//std::cout << "Test1 \n";
	std::vector<int>::iterator it;
	it = originpos.begin();
	originpos.insert(it,0);
	//std::cout << "Test2 \n";

	chromatin initialchromatin(simparams.at("nNucleosomes"), simparams.at("initstate"), simparams.at("cyclic"), originpos);

	//chromatin* initialchromatin = new chromatin(simparams.at("nNucleosomes"), simparams.at("initstate"), simparams.at("cyclic"), originpos);


	

	//initializing random number generator
	std::cout << "Initializing rand... \n";
	
	//initialchromatin.mPrintInfo();

	//TOAST

	return 0;
}
