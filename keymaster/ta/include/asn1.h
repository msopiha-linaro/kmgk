/*
 *
 * Copyright (C) 2017 GlobalLogic
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef ANDROID_OPTEE_ASN1_H
#define ANDROID_OPTEE_ASN1_H

#include <tee_internal_api.h>
#include <tee_internal_api_extensions.h>
#include <utee_defines.h>

#include "ta_ca_defs.h"
#include "generator.h"

#define CMD_ASN1_DECODE 0
#define CMD_ASN1_ENCODE_PUBKEY 1
#define CMD_EC_SIGN_ENCODE 2
#define CMD_EC_SIGN_DECODE 3
#define CMD_ASN1_GEN_ROOT_RSA_CERT 4
#define CMD_ASN1_GEN_ROOT_EC_CERT 5
#define CMD_ASN1_GEN_ATT_RSA_CERT 6
#define CMD_ASN1_GEN_ATT_EC_CERT 7
#define CMD_ASN1_GEN_ATT_EXTENSION 8

keymaster_error_t TA_decode_pkcs8(const TEE_TASessionHandle sessionSTA,
				keymaster_blob_t key_data,
				TEE_Attribute **attrs,
				uint32_t *attrs_count,
				const keymaster_algorithm_t algorithm,
				uint32_t *key_size,
				uint64_t *rsa_public_exponent);

keymaster_error_t TA_encode_ec_sign(const TEE_TASessionHandle sessionSTA,
				uint8_t *out, uint32_t *out_l);

keymaster_error_t TA_decode_ec_sign(const TEE_TASessionHandle sessionSTA,
				keymaster_blob_t *signature,
				uint32_t key_size);

keymaster_error_t TA_encode_key(const TEE_TASessionHandle sessionSTA,
				keymaster_blob_t *export_data,
				const uint32_t type,
				const TEE_ObjectHandle *obj_h,
				const uint32_t key_size);

TEE_Result TA_gen_root_rsa_cert(const TEE_TASessionHandle sessionSTA,
				TEE_ObjectHandle root_rsa_key,
				keymaster_blob_t *root_cert);

TEE_Result TA_gen_root_ec_cert(const TEE_TASessionHandle sessionSTA,
				TEE_ObjectHandle root_ec_key,
				keymaster_blob_t *root_cert);

TEE_Result TA_gen_attest_rsa_cert(const TEE_TASessionHandle sessionSTA,
				TEE_ObjectHandle attestedKey,
				keymaster_key_param_set_t *attest_params,
				keymaster_key_characteristics_t *key_chr,
				keymaster_cert_chain_t *cert_chain,
				uint8_t verified_boot);

TEE_Result TA_gen_attest_ec_cert(const TEE_TASessionHandle sessionSTA,
				TEE_ObjectHandle attestedKey,
				keymaster_key_param_set_t *attest_params,
				keymaster_key_characteristics_t *key_chr,
				keymaster_cert_chain_t *cert_chain,
				uint8_t verified_boot);

#endif/*ANDROID_OPTEE_ASN1_H*/
