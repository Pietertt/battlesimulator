#pragma once

namespace objects {
    class Object;
}

namespace Tmpl8 {

    class Rocket;
    class Beam;
    class Tank;
    class Game;

    class ActionVisitor : public Visitor {
        public:
            ActionVisitor();
            void visit_rocket(Rocket* rocket, Tank* tank) override;
            void visit_beam(Beam* rocket, Tank* tank) override;
            void visit_tank(Tank* tank, Tank* other) override;

            void add(Game* game);

        private:
            Game* game;

        protected:
    };
}