#include "../headers/rules.h"
#include "../headers/knowledge_base.h"
#include "../headers/CreateWindw.h"
#include "../headers/facts.h"
#include "../headers/menu.h"

#define MAX_LINE_SIZE 1024
#define MAX_PROP_SIZE 256

int main() {

	// Création des règles et de leurs prémisses & conclusion
	Rule Regle1 = createRule();
	Regle1 = addProposition(Regle1, "Circulaire");
	Regle1 = addProposition(Regle1, "Crevassée");
	Regle1 = addProposition(Regle1, "Persistant");
	Regle1 = addProposition(Regle1, "Gland");
	Regle1 = createConclusion(Regle1, "Chêne");

	Rule Regle2 = createRule();
	Regle2 = addProposition(Regle2, "Ovale");
	Regle2 = addProposition(Regle2, "Fissurée");
	Regle2 = addProposition(Regle2, "Marcescent");
	Regle2 = addProposition(Regle2, "Boule");
	Regle2 = createConclusion(Regle2, "Hêtre");

	Rule Regle3 = createRule();
	Regle3 = addProposition(Regle3, "Circulaire");
	Regle3 = addProposition(Regle3, "Lisse");
	Regle3 = addProposition(Regle3, "Caduc");
	Regle3 = addProposition(Regle3, "Samare");
	Regle3 = createConclusion(Regle3, "Erable");

	Rule Regle4 = createRule();
	Regle4 = addProposition(Regle4, "Circulaire");
	Regle4 = addProposition(Regle4, "Rugueuse");
	Regle4 = addProposition(Regle4, "Persistant");
	Regle4 = addProposition(Regle4, "Samare");
	Regle4 = createConclusion(Regle4, "Frêne");

	Rule Regle5 = createRule();
	Regle5 = addProposition(Regle5, "Triangulaire");
	Regle5 = addProposition(Regle5, "Lisse");
	Regle5 = addProposition(Regle5, "Marcescent");
	Regle5 = addProposition(Regle5, "Baie");
	Regle5 = createConclusion(Regle5, "If");

	Rule Regle6 = createRule();
	Regle6 = addProposition(Regle6, "Ovale");
	Regle6 = addProposition(Regle6, "Fissurée");
	Regle6 = addProposition(Regle6, "Caduc");
	Regle6 = addProposition(Regle6, "Gland");
	Regle6 = createConclusion(Regle6, "Noyer");

	// Création de la base de connaissance & ajout des règles dedans
	BC knowledge_basis = createBC();
	knowledge_basis = addRuleBC(knowledge_basis, Regle1);
	knowledge_basis = addRuleBC(knowledge_basis, Regle2);
	knowledge_basis = addRuleBC(knowledge_basis, Regle3);
	knowledge_basis = addRuleBC(knowledge_basis, Regle4);
	knowledge_basis = addRuleBC(knowledge_basis, Regle5);
	knowledge_basis = addRuleBC(knowledge_basis, Regle6);

    menu(knowledge_basis);

    return 0;
}