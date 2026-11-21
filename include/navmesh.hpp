/**
 * @file navmesh.hpp
 * @author Foxyy
 * @date 21 Nov 2026
 *
 * This file declares \link NavMesh \endlink interface.
 */

#pragma once

#include <set>

#include "RoomPosition.hpp"

/**
 * @namespace NavMesh
 * @brief NavMesh namespace.
 */
namespace NavMesh {
	/**
	 * @class POI
	 * @brief Represents a point of interest (POI) object.
	 */
	class POI {
	private:
		static size_t _id = 0;

		size_t id;
		POI_TYPE type; /**< The type of the POI. */
		RoomPosition pos; /**< The position of the POI. */

	public:
		/**
		 * @enum POI_TYPE
		 * @brief The type enumeration of POIs.
		 */
		enum POI_TYPE {
			HARVEST,
			UPGRADE,
			CONSTRUCT,
			GUARD
		};

		/**
		 * @brief POI Constructor
		 * 
		 * note: \link id \endlink is assigned automatically.
		 *
		 * @param type The type of the POI.
		 * @param poi The \c RoomPosition of the POI.
		 */
		POI(POI_TYPE type, RoomPosition pos);
	};

	/**
	 * @brief `less` comparator function for \link POI \endlink.
	 */
	bool operator < (const POI& poiA, const POI& poiB);

	/**
	 * @brief Registers a POI.
	 *
	 * @param poi The poi to register.
	 */
	void registerPOI(const POI& poi);

	/**
	 * @brief Unregisters a POI.
	 *
	 * @param poi The POI to unregister.
	 */
	void unregisterPOI(const POI& poi);

	/**
	 * @brief Unregisters a POI.
	 *
	 * @param poi_id The id of the POI to unregister.
	 */
	void unregisterPOI(size_t poi_id)
	
	// TODO: function for getting the nearest POI?
	// TODO: function for filtering POIs?
}
