/*
 * Copyright 2013 Evgeni Dobrev <evgeni_dobrev@developer.bg>
 * Copyright (c) 2015 - 2018, CUJO LLC.
 *
 * This library is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef STOMP_FRAME_H
#define STOMP_FRAME_H

#include "stomp.h"

typedef struct _frame frame_t;

frame_t *frame_new();
void frame_free(frame_t *f);
void frame_reset(frame_t *f);
int frame_cmd_set(frame_t *f, const char *cmd);
int frame_hdr_add(frame_t *f, const char *key, const char *val);
int frame_hdrs_add(frame_t *f, size_t hdrc, const struct stomp_hdr *hdrs);
int frame_body_set(frame_t *f, const void *body, size_t len);
ssize_t frame_write(struct lws* fd, frame_t *f);

size_t frame_cmd_get(frame_t *f, const char **cmd);
size_t frame_hdrs_get(frame_t *f, const struct stomp_hdr **hdrs);
size_t frame_body_get(frame_t *f, const void **body);
int frame_read(const unsigned char* buf, size_t len, frame_t *f);

#endif
