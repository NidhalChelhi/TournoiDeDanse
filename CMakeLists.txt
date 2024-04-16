cmake_minimum_required(VERSION 3.26)
project(TournoiDeDanse)

set(CMAKE_CXX_STANDARD 17)

add_executable(TournoiDeDanse main.cpp
        Personne.cpp
        Personne.h
        Adresse.cpp
        Adresse.h
        Danseur.cpp
        Danseur.h
        Style.cpp
        Style.h
        Juge.cpp
        Juge.h
        Competition.cpp
        Competition.h
        Session.cpp
        Session.h
        Critere.cpp
        Critere.h
        Salle.h
        Salle.cpp
        Resultat.h
        Resultat.cpp
        Tournoi.cpp
        Tournoi.h
)
