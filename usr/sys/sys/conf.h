#ifndef _SYS_CONF_H_
#define _SYS_CONF_H_

/*
 * Device routine type defenitions.
 */
typedef int d_open_t(struct device *dev);
typedef d_close_t(struct device *dev);
typedef d_read_t(struct device *dev, struct uio *uio);
typedef d_write_t(struct device *dev, struct uio *uio);

/*
 * Device switch-table.
 */
struct devsw {
	d_open_t	d_open;
	d_close_t	d_close;
	d_read_t	d_read;
	d_write_t	d_write;
};

#endif /* !_SYS_CONF_H_ */
