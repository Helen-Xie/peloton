/*-------------------------------------------------------------------------
 *
 * database.cpp
 * file description
 *
 * Copyright(c) 2015, CMU
 *
 * /n-store/src/catalog/database.cpp
 *
 *-------------------------------------------------------------------------
 */

#include "catalog/database.h"

namespace nstore {
namespace catalog {

bool Database::AddTable(Table* table) {
  if(std::find(tables.begin(), tables.end(), table) != tables.end())
    return false;
  tables.push_back(table);
  return true;
}

Table* Database::GetTable(const std::string &table_name) const {
  for(auto table : tables)
    if(table->GetName() == table_name)
      return table;
  return nullptr;
}

bool Database::RemoveTable(const std::string &table_name) {
  for(auto itr = tables.begin(); itr != tables.end() ; itr++)
    if((*itr)->GetName() == table_name) {
      tables.erase(itr);
      return true;
    }
  return false;
}

} // End catalog namespace
} // End nstore namespace
