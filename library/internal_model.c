// Copyright (c) 2020-2024. NetFoundry Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
//
// You may obtain a copy of the License at
// https://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.


#include <internal_model.h>
#include <ziti/ziti_model.h>
#include <ziti/errors.h>
#include <json-c/json.h>


#include <string.h>
#include <assert.h>
#include "ziti/ziti_buffer.h"
#include "ziti/ziti.h"

#if _WIN32
#include <stdint.h>
typedef uint32_t in_addr_t;
#define strcasecmp stricmp
#endif

#define null_checks(lh, rh) \
    if ((lh) == (rh)) { return 0; } \
    if ((lh) == NULL) { return -1; } \
    if ((rh) == NULL) { return 1; }

IMPL_ENUM(ziti_enrollment_method, ZITI_ENROLLMENT_METHOD)

IMPL_ENUM(jwt_sig_method, JWT_SIG_METHOD)

IMPL_ENUM(ziti_ctrl_cap, ZITI_CTRL_CAP_ENUM)

IMPL_ENUM(ziti_posture_query_type, ZITI_POSTURE_QUERY_TYPE_ENUM)

IMPL_ENUM(ziti_target_token, ZITI_SIGNER_TARGET_TOKEN)

IMPL_MODEL(ziti_posture_query, ZITI_POSTURE_QUERY_MODEL)

IMPL_MODEL(ziti_posture_query_set, ZITI_POSTURE_QUERY_SET_MODEL)

IMPL_MODEL(ziti_process, ZITI_PROCESS_MODEL)

IMPL_MODEL(ziti_service, ZITI_SERVICE_MODEL)

IMPL_MODEL(ziti_terminator, ZITI_TERMINATOR_MODEL)

IMPL_MODEL(ziti_client_cfg_v1, ZITI_CLIENT_CFG_V1_MODEL)

IMPL_MODEL(ziti_port_range, ZITI_PORT_RANGE_MODEL)

IMPL_MODEL(ziti_intercept_cfg_v1, ZITI_INTERCEPT_CFG_V1_MODEL)

IMPL_MODEL(ziti_listen_options, ZITI_LISTEN_OPTS_MODEL)

IMPL_MODEL(ziti_server_cfg_v1, ZITI_SERVER_CFG_V1_MODEL)

IMPL_ENUM(ziti_proxy_server_type, ZITI_PROXY_SERVER_TYPE_ENUM)

IMPL_MODEL(ziti_proxy_server, ZITI_PROXY_SERVER_MODEL)

IMPL_MODEL(ziti_address_translation, ZITI_ADDRESS_TRANSLATION_MODEL)

IMPL_MODEL(ziti_host_cfg_v1, ZITI_HOST_CFG_V1_MODEL)

IMPL_MODEL(ziti_host_cfg_v2, ZITI_HOST_CFG_V2_MODEL)

IMPL_MODEL(ziti_jwt_signer, ZITI_JWT_SIGNER_MODEL)

IMPL_MODEL(ziti_id_cfg, ZITI_ID_CFG_MODEL)

IMPL_MODEL(ziti_config, ZITI_CONFIG_MODEL)

IMPL_MODEL(ziti_er_protocols, ZITI_ER_PROTOCOLS)

IMPL_MODEL(ziti_edge_router, ZITI_EDGE_ROUTER_MODEL)

IMPL_MODEL(ziti_service_routers, ZITI_SERVICE_EDGE_ROUTERS_MODEL)

IMPL_MODEL(ziti_session, ZITI_SESSION_MODEL)

IMPL_MODEL(api_path, ZITI_API_PATH_MODEL)

IMPL_MODEL(ziti_api_versions, ZITI_API_VERSIONS_MODEL)

IMPL_MODEL(ziti_version, ZITI_VERSION_MODEL)

IMPL_MODEL(ziti_identity, ZITI_IDENTITY_MODEL)

IMPL_MODEL(ziti_auth_query_mfa, ZITI_AUTH_QUERY_MFA_MODEL)

IMPL_MODEL(ziti_api_session, ZITI_API_SESSION_MODEL)

IMPL_MODEL(ziti_error, ZITI_ERROR_MODEL)

IMPL_MODEL(ziti_sdk_info, ZITI_SDK_INFO_MODEL)

IMPL_MODEL(ziti_env_info, ZITI_ENV_INFO_MODEL)

IMPL_MODEL(ziti_auth_req, ZITI_AUTH_REQ)

IMPL_MODEL(ziti_enrollment_jwt_header, ZITI_ENROLLMENT_JWT_HEADER_MODEL)

IMPL_MODEL(ziti_enrollment_jwt, ZITI_ENROLLMENT_JWT_MODEL)

IMPL_MODEL(ziti_network_jwt, ZITI_NETWORK_JWT)

IMPL_MODEL(ziti_enrollment_resp, ZITI_ENROLLMENT_RESP)

IMPL_MODEL(ziti_pr_mac_req, ZITI_PR_MAC_REQ)

IMPL_MODEL(ziti_pr_os_req, ZITI_PR_OS_REQ)

IMPL_MODEL(ziti_pr_process, ZITI_PR_PROCESS)

IMPL_MODEL(ziti_pr_process_req, ZITI_PR_PROCESS_REQ)

IMPL_MODEL(ziti_pr_domain_req, ZITI_PR_DOMAIN_REQ)

IMPL_MODEL(ziti_pr_endpoint_state_req, ZITI_PR_ENDPOINT_STATE_REQ)

IMPL_MODEL(ziti_service_timer, ZITI_SERVICE_TIMER)

IMPL_MODEL(ziti_pr_response, ZITI_PR_RESPONSE)

IMPL_MODEL(ziti_service_update, ZITI_SERVICE_UPDATE)

IMPL_MODEL(ziti_mfa_recovery_codes, ZITI_MFA_RECOVERY_CODES_MODEL)

IMPL_MODEL(ziti_mfa_enrollment, ZITI_MFA_ENROLLMENT_MODEL)

IMPL_MODEL(ziti_mfa_code_req, ZITI_MFA_CODE_REQ)

IMPL_MODEL(ziti_identity_data, ZITI_IDENTITY_DATA_MODEL)

IMPL_MODEL(ziti_extend_cert_authenticator_req, ZITI_EXTEND_CERT_AUTHENTICATOR_REQ)

IMPL_MODEL(ziti_verify_extend_cert_authenticator_req, ZITI_VERIFY_EXTEND_CERT_AUTHENTICATOR_REQ)

IMPL_MODEL(ziti_authenticator, ZITI_AUTHENTICATOR_MODEL)

IMPL_MODEL(ziti_extend_cert_authenticator_resp, ZITI_EXTEND_CERT_AUTHENTICATOR_RESP)

IMPL_ENUM(ziti_session_type, ZITI_SESSION_TYPE_ENUM)

IMPL_ENUM(ziti_auth_query_type, ZITI_AUTH_QUERY_TYPE_ENUM)

IMPL_ENUM(ziti_protocol, ZITI_PROTOCOL_ENUM)

IMPL_MODEL(ziti_create_api_cert_req, ZITI_CREATE_API_CERT_REQ)

IMPL_MODEL(ziti_create_api_cert_resp, ZITI_CREATE_API_CERT_RESP)

IMPL_MODEL(api_address, API_ADDRESS_MODEL)

IMPL_MODEL(ctrl_apis, CTRL_APIS_MODEL)

IMPL_MODEL(ziti_controller_detail, ZITI_CONTROLLER_DETAIL)

IMPL_MODEL(ziti_pr_base, ZITI_PR_BASE);

bool ziti_service_has_permission(const ziti_service *service, ziti_session_type sessionType) {
    if (sessionType == ziti_session_types.Dial) {
        return (service->perm_flags & ZITI_CAN_DIAL) != 0;
    }

    if (sessionType == ziti_session_types.Bind) {
        return (service->perm_flags & ZITI_CAN_BIND) != 0;
    }

    return false;
}

const char *ziti_service_get_raw_config(ziti_service *service, const char *cfg_type) {
    return (const char *) model_map_get(&service->config, cfg_type);
}

int ziti_service_get_config(ziti_service *service, const char *cfg_type, void *cfg,
                            int (*parser)(void *, const char *, size_t)) {
    const char *cfg_json = ziti_service_get_raw_config(service, cfg_type);
    if (cfg_json == NULL) {
        return ZITI_CONFIG_NOT_FOUND;
    }

    if (parser(cfg, cfg_json, strlen(cfg_json)) < 0) {
        return ZITI_INVALID_CONFIG;
    };

    return ZITI_OK;
}

static int cmp_ziti_address0(ziti_address *lh, ziti_address *rh) {
    null_checks(lh, rh)

    if (lh->type != rh->type) {
        return (int) lh->type - (int) rh->type;
    }

    if (lh->type == ziti_address_hostname) {
        return strcmp(lh->addr.hostname, rh->addr.hostname);
    }

    if (lh->type == ziti_address_cidr) {
        return memcmp(&lh->addr.cidr, &rh->addr.cidr, sizeof(lh->addr.cidr));
    }
    return 0;
}

int parse_ziti_address_str(ziti_address *addr, const char *addr_str) {
    char *slash = strchr(addr_str, '/');
    unsigned long bits;
    const char *ip;
    char buf[64];

    memset(addr, '\0', sizeof *addr);

    if (slash) {
        char *endp = NULL;

        /**
         * parse prefix length, which is defined as a sequence of one or more decimal digits.
         */
        errno = 0;
        bits = strtoul(slash + 1, &endp, 10);
        if (errno || !endp || *endp != '\0')
            goto invalid_cidr;

        /**
         * prefix length must start with a decimal. zero is only allowed if
         * the prefix length is exactly one digit
         */
        if (slash == addr_str
            || slash[1] < '0' || slash[1] > '9' || (slash[1] == '0' && slash[2] != '\0'))
            goto invalid_cidr;

        size_t iplen = slash - addr_str;
        if (iplen >= sizeof buf)
            goto invalid_cidr;

        memcpy(buf, addr_str, iplen);
        buf[iplen] = '\0';
        ip = buf;
    } else {
        ip = addr_str;
    }

    addr->type = ziti_address_cidr;
    if (inet_pton(AF_INET, ip, (struct in_addr *) &addr->addr.cidr.ip) == 1) {
        if ((bits = slash ? bits : 32) > 32)
            goto invalid_cidr;
        addr->addr.cidr.af = AF_INET;
        addr->addr.cidr.bits = bits;
    } else if (inet_pton(AF_INET6, ip, &addr->addr.cidr.ip) == 1) {
        if ((bits = slash ? bits : 128) > 128)
            goto invalid_cidr;
        addr->addr.cidr.af = AF_INET6;
        addr->addr.cidr.bits = bits;
    } else {
invalid_cidr:
        addr->type = ziti_address_hostname;
        strncpy(addr->addr.hostname, addr_str, sizeof(addr->addr.hostname)-1);
        addr->addr.hostname[sizeof(addr->addr.hostname)-1] = '\0';
    }

    return 0;
}

static int ziti_address_from_j(ziti_address *addr, json_object *j, type_meta *m) {
    if (json_object_get_type(j) == json_type_string) {
        int rc = parse_ziti_address_str(addr, json_object_get_string(j));
        return rc;
    }
    return -1;
}

int ziti_address_print(char *buf, size_t max, const ziti_address *addr) {
    if (addr->type == ziti_address_hostname) {
        return snprintf(buf, max, "%s", addr->addr.hostname);
    } else {
        char ip[64];
        if (inet_ntop(addr->addr.cidr.af, &addr->addr.cidr.ip, ip, sizeof(ip)) == NULL) {
            return -1;
        }
        return snprintf(buf, max, "%s/%d", ip, addr->addr.cidr.bits);
    }
}

static json_object* ziti_address_to_j(const ziti_address *addr) {
    char addr_str[256];
    int n = ziti_address_print(addr_str, sizeof(addr_str), addr);
    assert(n > 0);

    return json_object_new_string_len(addr_str, n);
}

static int ziti_address_write_json(const ziti_address *addr, string_buf_t *buf, int indent, int flags) {
    char addr_str[256];
    if (ziti_address_print(addr_str, sizeof(addr_str), addr) < 0) {
        return -1;
    }

    return get_model_string_meta()->jsonifier(addr_str, buf, indent, flags);
}

static void free_ziti_address0(ziti_address *addr) {

}

int ziti_address_match(const ziti_address *addr, const ziti_address *range) {
    if (addr->type != range->type) {
        return -1;
    }

    if (addr->type == ziti_address_hostname) {
        if (range->addr.hostname[0] != '*') {
            return (strcasecmp(addr->addr.hostname, range->addr.hostname) == 0) ? 0 : -1;
        }

        const char *domain = range->addr.hostname + 2;

        const char *post_dot = addr->addr.hostname;
        while (post_dot != NULL) {
            if (strcasecmp(post_dot, domain) == 0) {
                return (int) (strlen(addr->addr.hostname) - strlen(domain));
            }

            post_dot = strchr(post_dot, '.');
            if (post_dot != NULL) {
                post_dot++;
            }
        }
    } else if (addr->type == ziti_address_cidr) {
        if (addr->addr.cidr.af != range->addr.cidr.af) { return -1; }
        if (addr->addr.cidr.bits < range->addr.cidr.bits) { return -1; }

        if (addr->addr.cidr.af == AF_INET) {
            in_addr_t mask = range->addr.cidr.bits == 0 ? 0 : htonl(-1UL << (32 - range->addr.cidr.bits));
            return (((struct in_addr *) &addr->addr.cidr.ip)->s_addr & mask) == (((struct in_addr *) &range->addr.cidr.ip)->s_addr & mask) ?
                   (int) addr->addr.cidr.bits - (int) range->addr.cidr.bits : -1;
        } else if (addr->addr.cidr.af == AF_INET6) {
            unsigned int bits = range->addr.cidr.bits;
            uint8_t mask;
            for (int i = 0; i < 16 && bits > 0; i++) {
                if (bits > 8) {
                    bits = bits - 8;
                    mask = 0xff;
                } else {
                    mask = 0xff << (8 - bits);
                    bits = 0;
                }

                if ((addr->addr.cidr.ip.s6_addr[i] & mask) != (range->addr.cidr.ip.s6_addr[i] & mask)) {
                    return -1;
                }
            }
            return addr->addr.cidr.bits - range->addr.cidr.bits;
        }
    }
    return -1;
}

int ziti_address_match_s(const char *addr, const ziti_address *range) {
    ziti_address a;

    int res = false;
    if (parse_ziti_address_str(&a, addr) == 0) {
        res = ziti_address_match(&a, range);
    }
    free_ziti_address(&a);
    return res;
}

int ziti_address_match_list(const ziti_address *addr, const model_list *range) {
    ziti_address a;

    int best = -1;
    const ziti_address *range_addr;
    MODEL_LIST_FOREACH(range_addr, *range) {
        int res = ziti_address_match(addr, range_addr);
        if (res == -1) { continue; }

        if (best == -1 || res < best) {
            best = res;
        }
    }
    return best;
}

int ziti_addrstr_match_list(const char *addr, const model_list *range) {
    ziti_address a;

    int best = -1;
    if (parse_ziti_address_str(&a, addr) == 0) {
        best = ziti_address_match_list(&a, range);
    }
    free_ziti_address(&a);
    return best;
}

int ziti_address_match_array(const char *addr, ziti_address **range) {
    ziti_address a;

    int best = -1;
    if (parse_ziti_address_str(&a, addr) == 0) {
        for (int i = 0; range[i] != NULL; i++) {
            int res = ziti_address_match(&a, range[i]);
            if (res == -1) { continue; }

            if (best == -1 || res < best) {
                best = res;
            }
        }
    }
    free_ziti_address(&a);
    return best;
}

bool ziti_protocol_match(ziti_protocol proto, const model_list *proto_list) {
    ziti_protocol *p;
    MODEL_LIST_FOREACH(p, *proto_list) {
        if (proto == *p) {
            return true;
        }
    }
    return false;
}

int ziti_port_match(int port, const model_list *port_range_list) {
    ziti_port_range *p;
    int score = -1;
    MODEL_LIST_FOREACH(p, *port_range_list) {
        if (p->low <= port && port <= p->high) {
            int width = p->high - p->low;
            if (score == -1 || score > width) {
                score = width;
            }
            if (score == 0) { // best possible score
                return score;
            }
        }
    }
    return score;
}

int ziti_intercept_match2(const ziti_intercept_cfg_v1 *intercept, ziti_protocol proto, const ziti_address *addr, int port) {
    if (proto != 0 && !ziti_protocol_match(proto, &intercept->protocols)) {
        return -1;
    }

    int addr_match = ziti_address_match_list(addr, &intercept->addresses);
    if (addr_match == -1) {
        return -1;
    }

    int port_match = ziti_port_match(port, &intercept->port_ranges);
    if (port_match == -1) {
        return -1;
    }

    // addr match takes precedence so push it into higher bits to get one value for intercept
    return (int) ((addr_match << 16) | (port_match & 0xFFFF));
}

int ziti_intercept_match(const ziti_intercept_cfg_v1 *intercept, ziti_protocol proto, const char *addr, int port) {
    ziti_address a;
    int match = -1;
    if (parse_ziti_address_str(&a, addr) >= 0) {
        match = ziti_intercept_match2(intercept, proto, &a, port);
    }
    free_ziti_address(&a);
    return match;
}


static type_meta ziti_address_META = {
        .name = "ziti_address",
        .size = sizeof(ziti_address),
        .comparer = (_cmp_f) cmp_ziti_address0,
        .jsonifier = (_to_json_f) ziti_address_write_json,
        .from_json = (from_json_func) ziti_address_from_j,
        .to_json = (to_json_func) ziti_address_to_j,
};

int ziti_intercept_from_client_cfg(ziti_intercept_cfg_v1 *intercept, const ziti_client_cfg_v1 *client_cfg) {
    memset(intercept, 0, sizeof(*intercept));

    ziti_protocol *proto = calloc(1, sizeof(ziti_protocol));
    *proto = ziti_protocols.tcp;
    model_list_append(&intercept->protocols, proto);
    proto = calloc(1, sizeof(ziti_protocol));
    *proto = ziti_protocols.udp;
    model_list_append(&intercept->protocols, proto);

    ziti_address *addr_copy = calloc(1, sizeof(ziti_address));
    memcpy(addr_copy, &client_cfg->hostname, sizeof(ziti_address));
    model_list_append(&intercept->addresses, addr_copy);

    ziti_port_range *range_copy = calloc(1, sizeof(ziti_port_range));
    range_copy->low = client_cfg->port;
    range_copy->high = client_cfg->port;
    model_list_append(&intercept->port_ranges, range_copy);

    return 0;
}

bool ziti_has_capability(const ziti_version *v, ziti_ctrl_cap c) {
    if (v != NULL && v->capabilities != NULL) {
        ziti_ctrl_cap **cap;
        for (int idx = 0; v->capabilities[idx] != NULL; idx++) {
            if (*v->capabilities[idx] == c) {
                return true;
            }
        }
    }
    return false;
}


IMPL_MODEL_FUNCS(ziti_address)
