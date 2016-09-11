#include "funcoes.h"

void readXMLFile(const char *path, Janela &MainWindow, Quadrado &Square)
{
    const char config_file_name[] = "config.xml";

    XMLDocument xml_file;
    XMLElement *pElem;
    XMLNode *pRoot;
    int width, height;
    int length;
    float colors[3];

    if(!path) //Verify if the path was provided
    {
        cout << "Path to config file not provided, the program will be finished" << endl;
        exit(1);
    }

    string pathFile = path;
    pathFile += config_file_name;
    //cout << pathFile << endl;

    //Opening file
    XMLError statusLoad = xml_file.LoadFile(pathFile.c_str());

    if(statusLoad != XML_SUCCESS) //Test if file has been opened correctly
    {
        cerr << "Error opening file" << endl;
        exit(XML_ERROR_FILE_READ_ERROR);
    }

    pRoot = xml_file.FirstChild(); //Get first element

    if(!pRoot)
    {
        cerr << "Error parsing element\n Program will be terminated" << endl;
        exit(XML_ERROR_PARSING_ELEMENT);
    }

    //cout << pRoot->Value() << endl;

    //Janela info
    pElem = pRoot->FirstChildElement("janela");
    width = atoi(pElem->FirstChildElement("largura")->GetText());
    //cout << "largura " << width << endl;
    MainWindow.setWidth(width);

    height = atoi(pElem->FirstChildElement("altura")->GetText());
    //cout << "altura " << height << endl;
    MainWindow.setHeight(height);

    pElem->FirstChildElement("fundo")->QueryAttribute("corR", &colors[RED]);
    pElem->FirstChildElement("fundo")->QueryAttribute("corG", &colors[GREEN]);
    pElem->FirstChildElement("fundo")->QueryAttribute("corB", &colors[BLUE]);
    //cout << "CorR " << colors[RED] << " CorG " << colors[GREEN] << " CorB " << colors[BLUE] << endl;
    MainWindow.setBgColors(colors);

    //cout << pRoot->FirstChildElement("janela")->FirstChildElement("titulo")->GetText() << endl;
    MainWindow.setTitle(pRoot->FirstChildElement("janela")->FirstChildElement("titulo")->GetText());

    //Quadrado info
    pElem = pRoot->FirstChildElement("quadrado");

    pElem->QueryAttribute("tamanho", &length);
    //cout << "tamanho " << length << endl;
    Square.setLength(length);

    pElem->QueryAttribute("corR", &colors[RED]);
    pElem->QueryAttribute("corG", &colors[GREEN]);
    pElem->QueryAttribute("corB", &colors[BLUE]);
    Square.setRGBColors(colors);
    //cout << "CorR " << colors[RED] << " CorG " << colors[GREEN] << " CorB " << colors[BLUE] << endl;

    return;
}