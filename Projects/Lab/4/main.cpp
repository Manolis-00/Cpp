#include "appSystem.h"

int main()
{
    GameApp starWars("234b", "Star Wars", "1.0.1", 20.99, true, "RPG");
    OfficeApp microsoftWord("345c", "Microsoft Word", "0.1.3", 98.99, {".doc", ".docx", ".pdf"});
    UserRating firstUserRating(3.4, "Tsekouris", "Not bad");
    ApplicationCreator firstApplicationCreator("456v", "Manolis Katopis", "ekatopis@gmail.com");

    Application angryBirds("123a", "Angry Birds", "4.0.1", 5.99);
    angryBirds.addUserRating(firstUserRating);
    angryBirds.addApplicationCreator(firstApplicationCreator);
    //angryBirds.showData();


    Application *witcher = new GameApp("567u", "witcher", "1.0.0", firstUserRating, firstApplicationCreator, 49.99, false, "RPG");
    witcher->addApplicationCreator(firstApplicationCreator);
    witcher->addUserRating(firstUserRating);

    OfficeApp adobeReader("678i", "Adobe Reader", "11.1.2", firstUserRating, firstApplicationCreator, 21.29, {".pdf", ".doc"});

    AppSystem applicationsList;
    applicationsList.addApplication(*witcher);
    applicationsList.addApplication(starWars);

    GameApp ghostOfTsushima("789v", "Ghost Of Tsushima", "0.0.1", 39.99, false, "Action - RPG");
    UserRating john13(4.1, "John13", "Great game");
    ApplicationCreator fromSoftware("890l", "FromSoftware", "fromsoftware@gmail.com");

    applicationsList.addCreatorsAndRatings(ghostOfTsushima, john13, fromSoftware);

    for(int i = 0; i < applicationsList.getTotalApplications(); i++)
        applicationsList.showData(applicationsList.getCurrentApplication(i));


    return 0;
}
