/**
 * @brief Benchmarking Cognitive Abilities of the Brain with Computer Games
 *
 * @file BrainBThread.cpp
 * @author  Norbert Bátfai <nbatfai@gmail.com>
 * @version 6.0.1
 *
 * @section LICENSE
 *
 * Copyright (C) 2017, 2018 Norbert Bátfai, nbatfai@gmail.com
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * @section DESCRIPTION
 *
 */

#include "BrainBThread.h"
#include <QTimer>

BrainBThread::BrainBThread ( int w, int h )
{

        dispShift = heroRectSize+heroRectSize/2;

        this->w = w - 3 * heroRectSize;
        this->h = h - 3 * heroRectSize;

        std::srand ( std::time ( 0 ) );

        Hero me ( this->w / 2 + 200.0 * std::rand() / ( RAND_MAX + 1.0 ) - 100,
                  this->h / 2 + 200.0 * std::rand() / ( RAND_MAX + 1.0 ) - 100, 255.0 * std::rand() / ( RAND_MAX + 1.0 ), 9 );
        me.samu=true;
        
        Hero other1 ( this->w / 2 + 200.0 * std::rand() / ( RAND_MAX + 1.0 ) - 100,
                      this->h / 2 + 200.0 * std::rand() / ( RAND_MAX + 1.0 ) - 100, 255.0 * std::rand() / ( RAND_MAX + 1.0 ), 5, "Norbi Entropy" );
        Hero other2 ( this->w / 2 + 200.0 * std::rand() / ( RAND_MAX + 1.0 ) - 100,
                      this->h / 2 + 200.0 * std::rand() / ( RAND_MAX + 1.0 ) - 100, 255.0 * std::rand() / ( RAND_MAX + 1.0 ), 3, "Greta Entropy" );
        Hero other4 ( this->w / 2 + 200.0 * std::rand() / ( RAND_MAX + 1.0 ) - 100,
                      this->h / 2 + 200.0 * std::rand() / ( RAND_MAX + 1.0 ) - 100, 255.0 * std::rand() / ( RAND_MAX + 1.0 ), 5, "Nandi Entropy" );
        Hero other5 ( this->w / 2 + 200.0 * std::rand() / ( RAND_MAX + 1.0 ) - 100,
                      this->h / 2 + 200.0 * std::rand() / ( RAND_MAX + 1.0 ) - 100, 255.0 * std::rand() / ( RAND_MAX + 1.0 ), 7, "Matyi Entropy" );

        heroes.push_back ( me );
        heroes.push_back ( other1 );
        heroes.push_back ( other2 );
        heroes.push_back ( other4 );
        heroes.push_back ( other5 );

  QTimer *timer = new QTimer(this);
connect(timer, &QTimer::timeout,[=](  ) { this->asd(); });//az asd(saját) szignál használata
connect(this,SIGNAL(asd()),this, SLOT(szinezes_samu()));//samu 5s-enként színt vált
connect(this,SIGNAL(asd()),this, SLOT(mozgas_samu()));//samu 5s-enként ugrik 
        timer->setInterval(5000);
        timer->start();

//szinezések meghívása
szinezes(); 
szinezes2();

}

BrainBThread::~BrainBThread()
{

}
void BrainBThread::szinezes_samu()
{
    

        for ( Hero & hero : heroes ) {
            if(hero.samu==true){
            double r=std::rand()%255;
            double g=std::rand()%255;
            double b=std::rand()%255;
            cv::Scalar ujc { r, g, b };
            cCentersam=ujc;
            }
        } 
}
void BrainBThread::mozgas_samu()
{
        samu_move_random();
}

void BrainBThread::szinezes_samu2()
{
    

        for ( Hero & hero : heroes ) {
            if(hero.samu==true){
            double r=std::rand()%255;
            double g=std::rand()%255;
            double b=std::rand()%255;
            cv::Scalar ujc { r, g, b };
            cCentersam=ujc;
            }
        }
    
}

void BrainBThread::szinezes()
{
        
            double r=std::rand()%255;
            double g=std::rand()%255;
            double b=std::rand()%255;
            cv::Scalar ujc { r, g, b };
           std::srand (1);
            double r2=std::rand()%255;
            double g2=std::rand()%255;
            double b2=std::rand()%255;
            cv::Scalar ujc2 { r2, g2, b2 };
            cBoxes=ujc;
            cBg=ujc2;//random háttér
        
}
void BrainBThread::szinezes2()
{
        
            double r=std::rand()%255;
            double g=std::rand()%255;
            double b=std::rand()%255;
            cv::Scalar ujc { r, g, b };
            std::srand (2);
            double r2=std::rand()%255;
            double g2=std::rand()%255;
            double b2=std::rand()%255;
            cv::Scalar ujc2 { r2, g2, b2 };
            cCenter=ujc;
            cCenteruj=ujc2;//random új entitás színe
        
}


void BrainBThread::run()
{
        while ( time < endTime ) {

                QThread::msleep ( delay );

                if ( !paused ) {

                        ++time;

                        devel();

                }

                draw();

        }

        emit endAndStats ( endTime );

}

void BrainBThread::pause()
{

        paused = !paused;
        if ( paused ) {
                ++nofPaused;
        }

}

void BrainBThread::set_paused ( bool p )
{

        if ( !paused && p ) {
                ++nofPaused;
        }

        paused = p;

}



