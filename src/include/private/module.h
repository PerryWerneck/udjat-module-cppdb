/* SPDX-License-Identifier: LGPL-3.0-or-later */

/*
 * Copyright (C) 2023 Perry Werneck <perry.werneck@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published
 * by the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

 /**
  * @brief Declare module clas.
  */

 #pragma once

 #include <udjat/defs.h>
 #include <udjat/module.h>
 #include <udjat/worker.h>
 #include <udjat/factory.h>
 #include <private/controller.h>

 namespace Udjat {

	namespace SQL {

		class UDJAT_PRIVATE Module : public Udjat::Module, private Udjat::Worker, private SQL::Controller, private Udjat::Factory {
		public:
			Module();
			virtual ~Module();

			// Udjat::Worker
			bool probe(const char *path) const noexcept override;
			bool work(Request &request, Response &response) const override;

			// Udjat::Factory
			std::shared_ptr<Activatable> ActivatableFactory(const Abstract::Object &parent, const pugi::xml_node &node) const override;
			bool generic(const pugi::xml_node &node) override;

		};

	}

 }