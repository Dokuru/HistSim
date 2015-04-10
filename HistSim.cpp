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


//using namespace std;

int main() {

	int verbose = 1;

	//parsing config file

	rapidxml::file<> xmlFile("config.cfg");
	rapidxml::xml_document<> doc;

	doc.parse<0>(xmlFile.data());

	std::map< std::string, boost::variant<std::string, int> > simparams;

	rapidxml::xml_node<> *node = doc.first_node("nNucleosomes");

	rapidxml::xml_attribute<> *attr;

	if(node)
	{
		attr = node->first_attribute("value");

		simparams["nNucleosomes"] = attr->value();

		if(verbose)
		{
			std::cout << "Number of nucleosomes: " << attr->value() << "\n ";
		}


	}
	else
	{
		std::cout << "Number of nucleosomes not defined! \n";

	}

	node = doc.first_node("histoneModifications");

	//TODO: support for multiple modification instances

	if(node)
	{
		for (rapidxml::xml_node<> *child = node->first_node(); child; child = child->next_sibling())
		{
			attr = child->first_attribute("type");

			simparams["modtype"] = attr->value();

			attr = child->first_attribute("value");

			simparams["modvalue"] = attr->value();

			if(verbose)
			{
				std::cout << "Modification type: " << simparams["modtype"] << "\n ";
				std::cout << "Modification value: " << simparams["modvalue"] << "\n ";
			}
		}
	}
	else
	{
		std::cout << "Histone modifications not defined! \n";
	}


	node = doc.first_node("cyclicChromosomes");

	if(node)
	{
		attr = node->first_attribute("value");

		simparams["cyclicChromosomes"] = attr->value();

		if(verbose)
		{
			std::cout << "Cyclic chromosomes: " << attr->value() << "\n ";
		}


	}
	else
	{
			std::cout << "Cyclic chromosomes not defined! \n";

	}


	node = doc.first_node("initialState");

	//TODO: support for multiple modification instances

	if(node)
	{
		for (rapidxml::xml_node<> *child = node->first_node(); child; child = child->next_sibling())
		{
			attr = child->first_attribute("type");

			std::string tmpstr = attr->value();

			if(!tmpstr.compare("custom"))
			{
				simparams["initstate"] = node->first_attribute("value")->value();
			}
			else if(!tmpstr.compare("twoParts"))
			{

				std::string& tmpstr = boost::get<std::string>(simparams["nNucleosomes"]);
				int boundary = atoi(tmpstr.c_str())/2;

				//std::cout << child->first_attribute("type")->value();

				//std::cout << boundary;

				simparams["initstate"] = "inProgress";

			}




			if(verbose)
			{
				std::cout << "Initial state: " << simparams["initstate"] << "\n ";
			}

		}
	}
	else
	{
		std::cout << "Number of nucleosomes not defined! \n";

	}



	//rapidxml::print(std::cout,doc,0);

	

	/* needed vars
	 
	int nNucleosomes
    int nSimulations
    int gRandSeed   
    int nReplications
    int visualizationState
    float replicationFreq 
    std::string outDirectory 
	std::string initialState
	
	*/
	
	//initializing nucleosome list / chromatin
	
	std::string test = "eintrag1|eintrag2";
	
	
	
	//cout << 
	
	//initializing random number generator

	//TOAST

	return 0;
}
