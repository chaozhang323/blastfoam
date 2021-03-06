/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     |
    \\  /    A nd           | Copyright (C) 2019 Synthetik Applied Technologies
     \\/     M anipulation  |
-------------------------------------------------------------------------------
License
    This file is derivative work of OpenFOAM.

    OpenFOAM is free software: you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    OpenFOAM is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
    for more details.

    You should have received a copy of the GNU General Public License
    along with OpenFOAM.  If not, see <http://www.gnu.org/licenses/>.

Class
    Foam::afterburnModel

Description
    Model to add additional energy based on afterburn reactions to increase the
    pressure of the JWL model.

SourceFiles
    afterburnModel.C
    newAfterburnModel.C

\*---------------------------------------------------------------------------*/

#ifndef afterburnModel_H
#define afterburnModel_H

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#include "volFields.H"
#include "surfaceFields.H"
#include "dictionary.H"
#include "runTimeSelectionTables.H"

namespace Foam
{

/*---------------------------------------------------------------------------*\
                           Class afterburnModel Declaration
\*---------------------------------------------------------------------------*/

class afterburnModel
{
protected:

    // Protected data

        //- Reference to mesh
        const fvMesh& mesh_;

        //- Dictionary containing coefficients
        const dictionary& dict_;


public:

    //- Runtime type information
    TypeName("afterburnModel");


    // Declare runtime construction

        declareRunTimeSelectionTable
        (
            autoPtr,
            afterburnModel,
            dictionary,
            (
                const fvMesh& mesh,
                const dictionary& dict
            ),
            (mesh, dict)
        );

    // Constructor
    afterburnModel(const fvMesh& mesh, const dictionary& dict);


    //- Destructor
    virtual ~afterburnModel();


    // Selectors

        static autoPtr<afterburnModel> New
        (
            const fvMesh& mesh,
            const dictionary& dict
        );


    // Member Functions

        //- Update
        virtual void update() = 0;

        //- Return pressure
        virtual tmp<volScalarField> Q() const = 0;
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
