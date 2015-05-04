
#include "nucleosome.hpp"

cNucleosome::cNucleosome(int iPosition_, std::string sHistoneStates_)
{
	iPosition = iPosition_;


	//mModifications;


	std::vector<std::string> histonelevel = explode(boost::lexical_cast<std::string>(sHistoneStates_),")");


	// (H2A[5.2])(H3[27.0])...


	//std::cout << histonelevel.size() << "\n";

	for(unsigned int i = 0; i < histonelevel.size(); ++i)
	{
		std::vector<std::string> histoneinfo = explode(boost::lexical_cast<std::string>(histonelevel[i]),"[");





		histoneinfo[0].erase(0, 1);

		histoneinfo[1].erase(histoneinfo[1].size() - 1);


		std::vector<std::string> siteinfo = explode(boost::lexical_cast<std::string>(histoneinfo[1]),".");


		//std::cout << "Histone " << histoneinfo[0] << " at site ";

		//std::cout << siteinfo[0] << " with state ";

		//std::cout << siteinfo[1] << " added.\n";


		int tmp2 = boost::lexical_cast<int>(siteinfo[0]);
		int tmp3 = boost::lexical_cast<int>(siteinfo[1]);


		//std::cout << "Histone " << histoneinfo[0] << " at site ";

		//std::cout << tmp2 << " with state ";

		//std::cout << tmp3 << " added.\n";

		mModifications[histoneinfo[0]][tmp2] = tmp3;

		std::cout << "Histone " << histoneinfo[0] << " at site ";

		std::cout << siteinfo[0] << " with state ";

		std::cout << mModifications[histoneinfo[0]][tmp2]  << " added.\n";
	}


	std::cout << "Nucleosome initialized.. \n";





}

cNucleosome::~cNucleosome() {
	// TODO destructor
}

