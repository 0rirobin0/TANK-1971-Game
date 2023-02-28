#include <SFML/System.hpp>
#include<iostream>
#include<vector>
#include <SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include <stdlib.h>









using namespace std;



int main()
{
Restart:

    int HealthTank1 = 100, HealthTank2 = 100;
    bool collisionOccurred1 = false;
    bool collisionOccurred2 = false;


    vector< pair<double, double>> rocket;
    vector< pair<double, double>> rocket2;
    sf::Clock clock1;
    sf::Clock clock2;
    sf::Clock clockgameover;
    // sf::Clock clockgameover;
   //  sf::Time delay = sf::seconds(1.0f);
    sf::RenderWindow window(sf::VideoMode(1000, 600), "TANK 1971");
    // Upload Image//




//Background image
    sf::Texture backgroundtexture;
    if (!backgroundtexture.loadFromFile("background.jpg"))
    {
        cout << "Background Image Loading Error!!!" << endl;
    }
    sf::Sprite backgroundsprite(backgroundtexture);

    //Tank1 image
    sf::Texture tank1texture;
    if (!tank1texture.loadFromFile("Tank1.png"))
    {
        cout << "Tank1 Image Loading Error!!!" << endl;
    }
    sf::Sprite tank1sprite(tank1texture);
    tank1sprite.setPosition(sf::Vector2f(680, 380));

    //Tank2 image
    sf::Texture tank2texture;
    if (!tank2texture.loadFromFile("Tank2.png"))
    {
        cout << "Tank2 Image Loading Error!!!" << endl;
    }
    sf::Sprite tank2sprite(tank2texture);
    tank2sprite.setPosition(sf::Vector2f(0, 480));


    //Fench
    sf::Texture fenchtexture;
    if (!fenchtexture.loadFromFile("fench.png"))
    {
        cout << "Fench Image Loading Error!!!" << endl;
    }

    sf::Sprite fenchsprite(fenchtexture);
    fenchsprite.setPosition(sf::Vector2f(410, 400));


    //rocket 1
    sf::Texture rockettexture;
    if (!rockettexture.loadFromFile("rocket1.png"))
    {
        cout << "rocket1 Image Loading Error!!!" << endl;
    }
    sf::Sprite rocketsprite(rockettexture);

    //rocket 2
    sf::Texture rockettexture2;
    if (!rockettexture2.loadFromFile("rocket2.png"))
    {
        cout << "rocket2 Image Loading Error!!!" << endl;
    }
    sf::Sprite rocketsprite2(rockettexture2);


    //Start image
    sf::Texture starttexture;
    if (!starttexture.loadFromFile("start.jpg"))
    {
        cout << "start Image Loading Error!!!" << endl;
    }
    sf::Sprite startsprite(starttexture);


    //End image
    sf::Texture endtexture;
    if (!endtexture.loadFromFile("end.jpg"))
    {
        cout << "end Image Loading Error!!!" << endl;
    }
    sf::Sprite endsprite(endtexture);



    //Foreground image
    sf::Texture foregroundtexture;
    if (!foregroundtexture.loadFromFile("foreground.png"))
    {
        cout << "Foreground Image Loading Error!!!" << endl;
    }
    sf::Sprite foregroundsprite(foregroundtexture);


    //Explotion image
    sf::Texture explotiontexture;
    if (!explotiontexture.loadFromFile("explotion.png"))
    {
        cout << "explotion Image Loading Error!!!" << endl;
    }
    sf::Sprite explotionsprite(explotiontexture);


    //fire spark2 image
    sf::Texture spark2texture;
    if (!spark2texture.loadFromFile("fire2spark.png"))
    {
        cout << "spark2 Image Loading Error!!!" << endl;
    }
    sf::Sprite spark2sprite(spark2texture);


    //fire spark1 image
    sf::Texture spark1texture;
    if (!spark1texture.loadFromFile("fire1spark.png"))
    {
        cout << "spark1 Image Loading Error!!!" << endl;
    }
    sf::Sprite spark1sprite(spark1texture);

    //Upload Font

    sf::Font font;
    if (!font.loadFromFile("Font/Calibri Bold.ttf"))
    {
        cout << "Calibri Font loading Error!!" << endl;
    }




    //Sound Upload
//background Music

    sf::SoundBuffer backgroundsoundbuffer;
    if (!backgroundsoundbuffer.loadFromFile("bgsound.wav"))
    {
        cout << "Backgroundsound load error" << endl;
    }
    sf::Sound backgroundsound;
    backgroundsound.setBuffer(backgroundsoundbuffer);

    //Sound bullet 1
    sf::SoundBuffer bulletsoundbuffer;
    if (!bulletsoundbuffer.loadFromFile("bulletsound1.wav"))
    {
        cout << "Bulletsound load error" << endl;
    }
    sf::Sound bulletsound;
    bulletsound.setBuffer(bulletsoundbuffer);


    //Sound tankdamage
    sf::SoundBuffer damagesoundbuffer;
    if (!damagesoundbuffer.loadFromFile("damage.wav"))
    {
        cout << "damage sound load error" << endl;
    }
    sf::Sound damagesound;
    damagesound.setBuffer(damagesoundbuffer);

    //Sound tank explosion
    sf::SoundBuffer explosionsoundbuffer;
    if (!explosionsoundbuffer.loadFromFile("explosion.wav"))
    {
        cout << "explosion sound load error" << endl;
    }
    sf::Sound explosionsound;
    explosionsound.setBuffer(explosionsoundbuffer);




    //bg music play


    backgroundsound.play();
    backgroundsound.setLoop(true);
    backgroundsound.setVolume(30);

    explosionsound.play();
    explosionsound.setVolume(30);







    //Start Image Draw flag
    bool gameplay = false;
    //end image Draw flag
    bool gameend = false;
    //game restart flag
    bool restart = false;
    //tank death
    bool tank1dead = false;
    bool tank2dead = false;
    //spark1 bool
    bool s1 = false;
    //spark2 bool
    bool s2 = false;



    ///////Game Loop/////

    while (window.isOpen())
    {






        //Event Loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }

            s2 = false;
            s1 = false;


            //Tank1_rocket1 event declaration 
            if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Numpad0 && tank1dead == false)
            {
                cout << "Numpad 0 has been released" << endl;


                if (clock1.getElapsedTime().asSeconds() >= 0.25f)
                {
                    rocket.push_back(make_pair(tank1sprite.getPosition().x, tank1sprite.getPosition().y));
                    //sound
                    bulletsound.play();
                    bulletsound.setVolume(20);
                }
                clock1.restart();
                s1 = true;
            }

            //Tank2_rocket2 event declaration 
            if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Space)
            {
                cout << "Space has been released" << endl;

                if (clock2.getElapsedTime().asSeconds() >= 0.25f && tank2dead == false)
                {
                    rocket2.push_back(make_pair(tank2sprite.getPosition().x, tank2sprite.getPosition().y));
                    //sound

                    bulletsound.play();
                    bulletsound.setVolume(20);
                }

                clock2.restart();

                s2 = true;

            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) gameplay = true;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) gameend = true;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y)) restart = true;
        }













        //Tank Move//
        if (gameplay == true) {
            if (HealthTank1 > 0) {
                //====TANK1====//     
                   //left Tank1
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                {
                    cout << "Left has been pressed" << endl;
                    if (tank1sprite.getPosition().x > (fenchsprite.getPosition().x) + 150) {
                        tank1sprite.move(sf::Vector2f(-0.5, 0));

                    }
                }
                //Right Tank 1
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                {
                    cout << "Right has been pressed" << endl;
                    if (tank1sprite.getPosition().x <= 900) {
                        tank1sprite.move(sf::Vector2f(0.5, 0));
                    }
                }
                //Up Tank 1
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                {
                    cout << "Up has been pressed" << endl;
                    if (tank1sprite.getPosition().y >= 380) {
                        tank1sprite.move(sf::Vector2f(0, -0.5f));
                    }
                }


                //Down Tank 1
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                {
                    cout << "Down has been pressed" << endl;
                    if (tank1sprite.getPosition().y <= 510) {
                        tank1sprite.move(sf::Vector2f(0, 0.5f));
                    }
                }
            }                            //====TANK 2=====//
            if (HealthTank2 > 0) {
                //left Tank2

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
                {
                    cout << "A has been pressed" << endl;
                    if (tank2sprite.getPosition().x >= 0) {
                        tank2sprite.move(sf::Vector2f(-0.5, 0));
                    }
                }
                //Right Tank 2
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
                {
                    cout << "D has been pressed" << endl;
                    if (tank2sprite.getPosition().x < (fenchsprite.getPosition().x) - 100) {
                        tank2sprite.move(sf::Vector2f(0.5, 0));
                    }
                }
                //Up Tank 2
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
                {
                    cout << "W has been pressed" << endl;
                    if (tank2sprite.getPosition().y >= 380) {
                        tank2sprite.move(sf::Vector2f(0, -0.5));
                    }
                }


                //Down Tank 2
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
                {
                    cout << "S has been pressed" << endl;
                    if (tank2sprite.getPosition().y <= 510) {
                        tank2sprite.move(sf::Vector2f(0, 0.5));
                    }
                }

            }
            //Collision & Health Decreasing//


//tank1 is fired

            if (tank1sprite.getGlobalBounds().intersects(rocketsprite2.getGlobalBounds()))
            {
                if (!collisionOccurred1) // check if collision has already occurred
                {
                    cout << "Tank 1 is fired" << endl;
                    HealthTank1 -= 10;
                    if (HealthTank1 > 0)
                    {
                        damagesound.play();
                        damagesound.setVolume(30);
                    }
                    if (HealthTank1 == 0)
                    {
                        explosionsound.play();
                        explosionsound.setVolume(30);
                        tank1dead = true;
                    }
                    cout << "Health1 " << HealthTank1 << endl;
                    if (HealthTank1 <= 0)cout << "Tank1 Destroyed    Tank2 Win " << endl;
                    collisionOccurred1 = true; // set collision flag to true
                }
            }
            else
            {
                collisionOccurred1 = false; // reset collision flag if no collision occurred
            }
            //tank2 is fired

            if (tank2sprite.getGlobalBounds().intersects(rocketsprite.getGlobalBounds()))
            {
                if (!collisionOccurred2) // check if collision has already occurred
                {
                    cout << "Tank 2 is fired" << endl;
                    HealthTank2 -= 10;
                    if (HealthTank2 > 0)
                    {
                        damagesound.play();
                        damagesound.setVolume(30);
                    }
                    if (HealthTank2 == 0)
                    {
                        explosionsound.play();
                        explosionsound.setVolume(30);
                        tank2dead = true;
                    }

                    cout << "Health2 " << HealthTank2 << endl;
                    if (HealthTank2 <= 0) {
                        cout << "Tank2 Destroyed    Tank1 Win " << endl;

                    }
                    collisionOccurred2 = true; // set collision flag to true
                }
            }
            else
            {
                collisionOccurred2 = false; // reset collision flag if no collision occurred
            }

        }

        //draw function//

        window.clear();


        window.draw(startsprite);

        //tank draw
        if (gameplay == true)
        {

            window.draw(backgroundsprite);


            if (HealthTank1 > 0) {
                window.draw(tank1sprite);
            }

            else {
                explotionsprite.setPosition(sf::Vector2f(tank1sprite.getPosition().x - 20, tank1sprite.getPosition().y - 40));

                window.draw(explotionsprite);

            }
            if (HealthTank2 > 0) {
                window.draw(tank2sprite);
            }
            else {
                explotionsprite.setPosition(sf::Vector2f(tank2sprite.getPosition().x - 20, tank2sprite.getPosition().y - 40));

                window.draw(explotionsprite);

            }

            //Tank1 Name print

            sf::Text text1("TANK 1 ", font, 20);
            text1.setFillColor(sf::Color::White);
            text1.setPosition(tank1sprite.getPosition().x, tank1sprite.getPosition().y - 40);
            if (HealthTank1 > 0) {
                window.draw(text1);
            }
            //Tank1 Name print

            sf::Text text2("TANK 2 ", font, 20);
            text2.setFillColor(sf::Color::White);
            text2.setPosition(tank2sprite.getPosition().x, tank2sprite.getPosition().y - 40);
            if (HealthTank2 > 0) {
                window.draw(text2);
            }



            //Tank1 life draw

            if (HealthTank1 > 0) {
                sf::RectangleShape healthBar(sf::Vector2f(HealthTank1, 5));

                if (HealthTank1 >= 60)
                    healthBar.setFillColor(sf::Color::White);
                if (HealthTank1 >= 40 && HealthTank1 < 60)
                    healthBar.setFillColor(sf::Color::Yellow);
                if (HealthTank1 > 0 && HealthTank1 < 40)
                    healthBar.setFillColor(sf::Color::Red);
                healthBar.setPosition(tank1sprite.getPosition().x, tank1sprite.getPosition().y - 10);
                window.draw(healthBar);
            }
            //Tank1 life draw

            if (HealthTank2 > 0) {
                sf::RectangleShape healthBar2(sf::Vector2f(HealthTank2, 5));

                if (HealthTank2 >= 60)
                    healthBar2.setFillColor(sf::Color::White);
                if (HealthTank2 >= 40 && HealthTank2 < 60)
                    healthBar2.setFillColor(sf::Color::Yellow);
                if (HealthTank2 > 0 && HealthTank2 < 40)
                    healthBar2.setFillColor(sf::Color::Red);
                healthBar2.setPosition(tank2sprite.getPosition().x, tank2sprite.getPosition().y - 10);
                window.draw(healthBar2);
            }







            //rocket1 draw&&move
            if (!tank1dead) {
                if (!rocket.empty())
                {
                    for (int i = 0; i < rocket.size(); i++)
                    {
                        rocket[i].first -= 0.5;
                        if (rocket[i].first < -10)
                        {
                            continue;
                        }

                        rocketsprite.setPosition(sf::Vector2f(rocket[i].first, rocket[i].second + 10));


                        if (!collisionOccurred2)
                            window.draw(rocketsprite);

                    }
                }
            }int s = 0;
            //rocket2 draw&&move
            if (!tank2dead)
            {
                if (!rocket2.empty())
                {
                    for (int i = 0; i < rocket2.size(); i++)
                    {


                        rocket2[i].first += 0.5;
                        if (rocket2[i].first > 900)
                        {
                            continue;
                        }


                        rocketsprite2.setPosition(sf::Vector2f(rocket2[i].first + 100, rocket2[i].second + 10));


                        window.draw(rocketsprite2);








                    }

                }

            }






            window.draw(fenchsprite);
            window.draw(foregroundsprite);

            //spark draw
               //spark2
            if (s2 == true)
            {
                spark2sprite.setPosition(sf::Vector2f(tank2sprite.getPosition().x + 100, tank2sprite.getPosition().y));


                window.draw(spark2sprite);
            }
            //spark1

            //spark2
            if (s1 == true)
            {
                spark1sprite.setPosition(sf::Vector2f(tank1sprite.getPosition().x - 20, tank1sprite.getPosition().y));


                window.draw(spark1sprite);
            }






            //Game Over showing


            if (HealthTank1 <= 0 || HealthTank2 <= 0)
            {



                sf::Text textover("GAME OVER", font, 100);
                textover.setFillColor(sf::Color::White);
                textover.setPosition(sf::Vector2f(260, 200));
                window.draw(textover);

                sf::Text textesc("Press Esc", font, 20);
                textesc.setFillColor(sf::Color::White);
                textesc.setPosition(sf::Vector2f(450, 320));
                window.draw(textesc);

            }





            //End Page draw
            if (gameend == true)
            {

                if (HealthTank1 <= 0 || HealthTank2 <= 0)
                {


                    window.draw(endsprite);

                    if (HealthTank2 <= 0)
                    {
                        //Tank1 Win print

                        sf::Text textwin1("TANK 1 WIN :) ", font, 60);
                        textwin1.setFillColor(sf::Color::White);
                        textwin1.setPosition(sf::Vector2f(360, 300));
                        window.draw(textwin1);

                    }
                    else if (HealthTank1 <= 0)
                    {
                        //Tank2 Win print

                        sf::Text textwin2("TANK 2 WIN :) ", font, 60);
                        textwin2.setFillColor(sf::Color::White);
                        textwin2.setPosition(sf::Vector2f(360, 300));
                        window.draw(textwin2);

                    }



                }


            }

            if (gameend == true && restart == true) goto Restart;



        }

        window.display();



    }




    return 0;
}