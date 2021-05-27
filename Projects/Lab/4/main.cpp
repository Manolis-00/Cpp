#include "AppSystem.h"

int main()
{
    GameApp starWars("234b", "Star Wars", "1.0.1", 20.99, true, "RPG");
    OfficeApp microsoftWord("345c", "Microsoft Word", "0.1.3", 98.99, {".doc", ".docx", ".pdf"});
    UserRating firstUserRating(3.4, "Tsekouris", "Not bad");
    ApplicationCreator firstApplicationCreator("456v", "Manolis Katopis", "ekatopis@gmail.com");

    Application angryBirds("123a", "Angry Birds", "4.0.1", 5.99);
    angryBirds.addUserRating(firstUserRating);
    angryBirds.addApplicationCreator(firstApplicationCreator);

    GameApp *witcher = new GameApp("567u", "witcher", "1.0.0", firstUserRating, firstApplicationCreator, 49.99, false, "RPG");
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
    applicationsList.addApplication(adobeReader);
    applicationsList.addApplication(microsoftWord);

    applicationsList.addCreatorsAndRatings(microsoftWord, john13, firstApplicationCreator);

    applicationsList.setApplicationId(*witcher, "576a");

    applicationsList.setApplicationName(starWars, "star wars");

    ApplicationCreator cdProjecktRed("12345", "CDProjektRed", "cdprojecktred@gmail.com");
    applicationsList.setCreatorDetails(*witcher, cdProjecktRed);

    UserRating jim(4.9, "Jimmy", "a masterpiece");
    applicationsList.addUserRatings(*witcher, jim);

    applicationsList.deleteAppType(microsoftWord, 2);

    applicationsList.addAppType(microsoftWord, "pdf");

    OfficeApp libreOffice("99z", "Libre Office", "0.0.5", 0.0, {".doc", ".docx", ".xls"});

    applicationsList.addApplication(libreOffice);

    //applicationsList.showData();

    //applicationsList.showDataToFile();

    ApplicationCreator newCreator;

    newCreator.readDetailsFromFile("D:\\Department of Computer Engineering and Computer Science\\Computer Programming\\Meletioy C++\\Lab\\Exercise 4.2\\creator.txt");

    //newCreator.showData();

    UserRating johnDoe;

    johnDoe.readRatingFromFile("D:\\Department of Computer Engineering and Computer Science\\Computer Programming\\Meletioy C++\\Lab\\Exercise 4.2\\rating.txt");

    //johnDoe.showData();

    GameApp vampyr;

    vampyr.readGameDataFromFile("D:\\Department of Computer Engineering and Computer Science\\Computer Programming\\Meletioy C++\\Lab\\Exercise 4.2\\game.txt");
    vampyr.addUserRating(johnDoe);
    vampyr.addApplicationCreator(newCreator);
    //vampyr.showData();

    OfficeApp cLion;
    cLion.readAppDataFromFile("D:\\Department of Computer Engineering and Computer Science\\Computer Programming\\Meletioy C++\\Lab\\Exercise 4.2\\officeApp.txt");
    cLion.addUserRating(johnDoe);
    cLion.addApplicationCreator(newCreator);
    cLion.showData();

    return 0;
}
