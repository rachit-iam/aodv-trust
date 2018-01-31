//#include "stdafx.h"
#include "BackupTable.h"
#include <iostream>

namespace ns3
{
namespace aodv
{

BackupTable* BackupTable::instance = NULL;


BackupTable::BackupTable()
{
	columnSeperator = " | ";
}

BackupTable * BackupTable::getInstance()
{
	if (instance == NULL) {
		instance = new BackupTable();
	}
	return instance;
}

void BackupTable::addBackupTableEntry(BackupTableEntry entry)
{
	backupTableRecords.push_back(entry);
}

std::vector<BackupTableEntry>& BackupTable::getBackupTableEntries()
{
	return backupTableRecords;
}

void BackupTable::printTable()
{
	std::cout << ">>>>>>>>>>>>>> Backup Table <<<<<<<<<<<<<<<" << std::endl;
	std::cout << "| " << "Node" << columnSeperator << "Trust Value" << columnSeperator << "Time Duration" << columnSeperator << "Analyzed Result" << std::endl;

	for (BackupTableEntry &node : backupTableRecords) {
		std::cout << "| " << node.getNeiNode()->getNodeName() << columnSeperator << node.getTrustValue() << "\t" << columnSeperator << node.getTimeDuration() << "\t\t" << columnSeperator << node.getResult() << std::endl;
	}
}

void BackupTable::addToTrustList(double trustValue)
{
	this->trustList.push_back(trustValue);
}

std::vector<double>& BackupTable::getTrustList()
{
	return this->trustList;
}


BackupTable::~BackupTable()
{
}

}
}
