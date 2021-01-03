
set(HERALD_HEADERS 
	${HERALD_BASE}/include/herald.h
	${HERALD_BASE}/include/herald/datatype/stdlib.h

	${HERALD_BASE}/include/herald/context.h
	${HERALD_BASE}/include/herald/device.h
  ${HERALD_BASE}/include/herald/default_sensor_delegate.h
  ${HERALD_BASE}/include/herald/sensor_array.h 
  ${HERALD_BASE}/include/herald/sensor_delegate.h
  ${HERALD_BASE}/include/herald/sensor.h
  ${HERALD_BASE}/include/herald/ble/ble_concrete.h
  ${HERALD_BASE}/include/herald/ble/ble_database_delegate.h
  ${HERALD_BASE}/include/herald/ble/ble_database.h
  ${HERALD_BASE}/include/herald/ble/ble_device_delegate.h
  ${HERALD_BASE}/include/herald/ble/ble_device.h
  ${HERALD_BASE}/include/herald/ble/ble_mac_address.h
  ${HERALD_BASE}/include/herald/ble/ble_receiver.h
  ${HERALD_BASE}/include/herald/ble/ble_sensor.h
  ${HERALD_BASE}/include/herald/ble/ble_sensor_configuration.h
  ${HERALD_BASE}/include/herald/ble/ble_transmitter.h
  ${HERALD_BASE}/include/herald/ble/ble_tx_power.h
  ${HERALD_BASE}/include/herald/ble/bluetooth_state_manager.h
  ${HERALD_BASE}/include/herald/ble/bluetooth_state_manager_delegate.h
  ${HERALD_BASE}/include/herald/ble/filter/ble_advert_parser.h
  ${HERALD_BASE}/include/herald/ble/filter/ble_advert_types.h
  ${HERALD_BASE}/include/herald/data/sensor_logger.h
  ${HERALD_BASE}/include/herald/datatype/base64_string.h 
  ${HERALD_BASE}/include/herald/datatype/bluetooth_state.h
  ${HERALD_BASE}/include/herald/datatype/data.h
  ${HERALD_BASE}/include/herald/datatype/date.h
  ${HERALD_BASE}/include/herald/datatype/encounter.h
  ${HERALD_BASE}/include/herald/datatype/error_code.h
  ${HERALD_BASE}/include/herald/datatype/immediate_send_data.h
  ${HERALD_BASE}/include/herald/datatype/location_reference.h
  ${HERALD_BASE}/include/herald/datatype/location.h
  ${HERALD_BASE}/include/herald/datatype/payload_data.h
  ${HERALD_BASE}/include/herald/datatype/payload_sharing_data.h
  ${HERALD_BASE}/include/herald/datatype/payload_timestamp.h
  ${HERALD_BASE}/include/herald/datatype/placename_location_reference.h
  ${HERALD_BASE}/include/herald/datatype/proximity.h
  ${HERALD_BASE}/include/herald/datatype/pseudo_device_address.h
  ${HERALD_BASE}/include/herald/datatype/randomness.h
  ${HERALD_BASE}/include/herald/datatype/rssi.h
  ${HERALD_BASE}/include/herald/datatype/sensor_state.h
  ${HERALD_BASE}/include/herald/datatype/sensor_type.h
  ${HERALD_BASE}/include/herald/datatype/signal_characteristic_data.h
  ${HERALD_BASE}/include/herald/datatype/target_identifier.h
  ${HERALD_BASE}/include/herald/datatype/time_interval.h
  ${HERALD_BASE}/include/herald/datatype/wgs84.h
  ${HERALD_BASE}/include/herald/payload/payload_data_supplier.h
  ${HERALD_BASE}/include/herald/payload/beacon/beacon_payload_data_supplier.h
  ${HERALD_BASE}/include/herald/payload/fixed/fixed_payload_data_supplier.h
  ${HERALD_BASE}/include/herald/payload/extended/extended_data.h

)
set(HERALD_HEADERS_ZEPHYR 
  ${HERALD_BASE}/include/herald/zephyr_context.h
)
set(HERALD_SOURCES
  ${HERALD_BASE}/src/ble/ble_mac_address.cpp
  ${HERALD_BASE}/src/ble/ble_device.cpp
  ${HERALD_BASE}/src/ble/concrete_ble_sensor.cpp
  ${HERALD_BASE}/src/ble/concrete_ble_database.cpp
  ${HERALD_BASE}/src/ble/filter/ble_advert_parser.cpp
  ${HERALD_BASE}/src/ble/filter/ble_advert_types.cpp
  ${HERALD_BASE}/src/data/sensor_logger.cpp
	${HERALD_BASE}/src/datatype/base64_string.cpp
	${HERALD_BASE}/src/datatype/data.cpp
	${HERALD_BASE}/src/datatype/date.cpp
	${HERALD_BASE}/src/datatype/encounter.cpp
	${HERALD_BASE}/src/datatype/immediate_send_data.cpp
	${HERALD_BASE}/src/datatype/location.cpp
	${HERALD_BASE}/src/datatype/payload_data.cpp
	${HERALD_BASE}/src/datatype/pseudo_device_address.cpp
	${HERALD_BASE}/src/datatype/rssi.cpp
	${HERALD_BASE}/src/datatype/signal_characteristic_data.cpp
	${HERALD_BASE}/src/datatype/target_identifier.cpp
	${HERALD_BASE}/src/datatype/time_interval.cpp
	${HERALD_BASE}/src/datatype/uuid.cpp
	${HERALD_BASE}/src/payload/beacon/beacon_payload_data_supplier.cpp
	${HERALD_BASE}/src/payload/fixed/fixed_payload_data_supplier.cpp
	${HERALD_BASE}/src/payload/extended/extended_data.cpp
  ${HERALD_BASE}/src/default_sensor_delegate.cpp
  ${HERALD_BASE}/src/context.cpp
  ${HERALD_BASE}/src/sensor_array.cpp
)
set(HERALD_SOURCES_ZEPHYR
  ${HERALD_BASE}/src/ble/zephyr/concrete_ble_transmitter_nrf.cpp
  ${HERALD_BASE}/src/ble/zephyr/concrete_ble_receiver_nrf.cpp
  ${HERALD_BASE}/src/zephyr_context.cpp
)
