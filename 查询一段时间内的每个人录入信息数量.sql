SELECT
	b.user_name,
	b.user_tag,
	c.station,
	c.station_uid,
	a.acc_count
FROM
	(
		SELECT
			typein_officer AS user_id,
			COUNT(*) AS acc_count
		FROM
			EVENTS
		WHERE
			UNIX_TIMESTAMP(typein_time) >= UNIX_TIMESTAMP('2016-10-1')
		AND UNIX_TIMESTAMP(typein_time) <= UNIX_TIMESTAMP(
			DATE_ADD('2016-10-31', INTERVAL 1 DAY)
		)
		AND check_state = '1'
		GROUP BY
			typein_officer
	) AS a
INNER JOIN users AS b ON a.user_id = b.user_id
INNER JOIN view_station c ON b.user_unit = c.station_id