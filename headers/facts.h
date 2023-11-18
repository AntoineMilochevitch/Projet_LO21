#ifndef __FACTS__H__
#define __FACTS__H__

#include "../headers/rules.h"
#include "../headers/knowledge_base.h"

typedef struct facts {
    Proposition *facts;
    struct facts *next;
} Facts;

typedef Facts *BF;


/********************************
 * @brief function creating an empty knowledge base
 * 
 * @param new_bc variable accepting the new knowledge base
 * @return knowledge base created
 */ 
BF createBF();


/********************************
 * @brief function adding a fact to the fact base
 * 
 * @param bf fact base to which the fact will be added
 * @param content fact to add
 * @return fact base with the fact added
 */
BF addFactBF(BF bf, char *content);


/********************************
 * @brief function checking if a fact base is empty
 * 
 * @param bf fact base to check
 * @return true if the fact base is empty, false otherwise
 */
bool isEmptyBF(BF bf);


/********************************
 * @brief function deleting the fact base
 * 
 * @param bf fact base to delete
 * @return fact base deleted (NULL)
 */
void deleteBF(BF bf);


/********************************
 * @brief function displaying the fact base
 * 
 * @param bf fact base to display
 */
void displayBF(BF bf);

#endif